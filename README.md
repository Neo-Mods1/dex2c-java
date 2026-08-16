# dex2c-cli

`dex2c-cli` is a standalone command-line compiler that translates Dalvik bytecode — from raw `.dex` files, APKs, or Zips — into JNI-ready C++ source code. Each method is lowered through a full IR pipeline (control-flow graph, SSA, register allocation) and emitted as a native function that can be built into a `.so` and loaded with `System.loadLibrary`.

Beyond generating source, the `build` command runs the complete dex2c pipeline on an APK: it compiles methods to C++, builds the `.so` with the Android NDK, rewrites the DEX so every compiled method is `native`, injects the `System.loadLibrary` call into the Application class, repacks and zipaligns the APK, and signs it.

It is a **CLI/fat-JAR project**, not an Android library, and does not build an AAR.

## Pipeline

```text
APK / ZIP / DEX
      |
      v
classes*.dex extraction
      |
      v
Google smali dexlib2 3.0.9
      |
      v
GraphBuilder
  - basic-block leaders
  - branches / fall-through
  - switch targets
  - try/catch edges
  - RPO
  - immediate dominators
      |
      v
BlockLifter
      |
      v
DEX IR
  Value / Variable / Constant / Phi / Instruction / DexInstruction
      |
      v
Braun-style SSA builder
  - current definitions
  - recursive reads
  - incomplete phis
  - block sealing
  - trivial-phi removal
  - type propagation / verification
      |
      v
RegisterAllocator
      |
      v
JNI C++ writer
  - arithmetic
  - constants
  - branches
  - arrays
  - fields
  - invokes
  - object allocation
  - casts / instanceof
  - monitor operations
  - exception landing pads
      |
      v
.dex2c.cpp
```

## Features

- Input: `.dex`, `.apk`, or `.zip`; multidex (`classes*.dex`) is fully supported
- Complete IR pipeline: control-flow graph, Braun-style SSA, register allocation
- JNI C++ output with native exception checks and landing-pad dispatch
- Filter compilation by class, method, or full descriptor regex
- `inspect` mode to dump classes/methods from an input without compiling
- Unsupported instructions are diagnosed explicitly, never silently skipped

## Opcode coverage

The instruction lowerer is name-driven and supports the following families:

- move / move-result / move-exception
- integer, long, float and double arithmetic
- `/2addr` arithmetic
- literal arithmetic
- unary neg/not
- numeric conversions
- comparisons
- conditional branches
- goto
- packed/sparse switch CFGs
- constants
- arrays and array length
- field reads/writes
- method invocation, including range invokes
- object allocation
- new-array / filled-new-array
- check-cast / instance-of
- monitor enter/exit
- throw/return
- JNI exception checks and try/catch landing-pad dispatch

New DEX opcodes can be added without an external instruction wrapper — lowering is name-driven, and the input is parsed directly with dexlib2.

## Dependencies

- `com.android.tools.smali:smali-dexlib2:3.0.9`
- ASM `9.10.1` (for JVM-side analysis/transformation extensions; not used as a DEX parser)
- Shadow for the executable fat JAR

## Build

Requires JDK 11+ and Gradle 8.x.

```bash
./gradlew clean build
```

Output:

```text
build/libs/dex2c-cli-2.0.0-all.jar
```

## CLI

```bash
java -jar build/libs/dex2c-cli-2.0.0-all.jar --help
```

Compile a DEX:

```bash
java -jar build/libs/dex2c-cli-2.0.0-all.jar \
  --input classes.dex \
  --output out
```

Compile an APK/multidex APK:

```bash
java -jar build/libs/dex2c-cli-2.0.0-all.jar \
  --input app.apk \
  --output out
```

Filter:

```bash
--class 'Lcom/example/.*'
--method 'foo|bar'
--filter 'Lcom/example/Test;->foo(I)I'
```

Inspect without compiling:

```bash
java -jar build/libs/dex2c-cli-2.0.0-all.jar \
  --command inspect \
  --input app.apk
```

Build a hardened APK (compile → NDK `.so` → mark native → repack → sign):

```bash
java -jar build/libs/dex2c-cli-2.0.0-all.jar \
  --command build \
  --input app.apk \
  --output app-dex2c.apk
```

The `build` command discovers `ndk-build` from `--ndk-dir` or `ANDROID_NDK_HOME`, and `zipalign`/`apksigner` from `--zipalign`/`--apksigner` or the Android build-tools directory. A debug keystore is generated automatically when none is given. Useful flags:

```bash
--lib-name mylib      # LOCAL_MODULE name (default: stub)
--dynamic-register    # register natives via RegisterNatives instead of static exports
--min-sdk 21          # native build + apksigner target SDK
--lib-abis arm64-v8a,armeabi-v7a
--no-build            # only generate the JNI project, do not run ndk-build
--source-dir ./project
--disable-signing     # skip zipalign/apksigner
--keystore ks.jks --alias mykey --ks-pass pass:secret --key-pass pass:secret
```

The Application class is located from the manifest's `android:name`; the APK must declare one so the library load can be injected.

### Config file

A protector.cfg-style INI config fills every unset option and is loaded
automatically from `protector.cfg` in the CWD — or from any path with
`--config <file>` (the same file works for both dex2c-cli and the reference
Python `protect.py`; unknown keys are ignored). Command-line arguments always
override the config. Relative paths resolve against the CWD.

```ini
[protection]
native_lib = "NT1"

[paths]
input_apk = ""        # or use -i
output_apk = ""       # or use -o
ndk_dir = ""
apksigner = ""
zipalign = ""

[signing]
keystore = "nt-protector/release.jks"
alias = "release"
keystore_pass = "secret"
store_pass = "secret"
v1_enabled = true
v2_enabled = true
v3_enabled = true

[filter]
include = [ "bin/nt/**", ]   # pkg paths; '**' crosses segments, '*' one segment
exclude = [ "bin/nt/main/App", ]
```

`[filter]` rules translate to dex2c method filters (includes) and keep-rules
(excludes). When the Application class itself is a compile target, its
`<clinit>` is spared from compilation so the injected `System.loadLibrary`
call keeps running from the DEX.

### Application class fallback

APKs without an `application android:name` in the manifest are unsupported by
`System.loadLibrary` injection alone. In that case dex2c generates a loader
class — a real `android.app.Application` subclass named `App` in the app's
own package (e.g. `bin.nt.main.App`), whose `onCreate()` calls
`super.onCreate()` then `System.loadLibrary` — patches the manifest
`android:name` (strings are appended to the existing binary string pool, all
other chunks stay byte-identical), and keeps the generated class out of the
compilation so its bodies survive the rewrite. Configure it with
`loader_class = "..."` or `--custom-loader <class>` (dotted or `L...;`).

## Testing

The test suite covers the IR pipeline (graph, SSA, phi cleanup) and the C++ writer end-to-end:

- `PortSmokeTest` — graph construction, RPO, dominators, trivial-phi removal
- `WriterSmokeTest` — a method lowered through the full pipeline to JNI C++

Continuous integration (`.github/workflows/build.yml`) builds the fat JAR, runs both smoke tests, compiles and inspects the real APK under `test/` (`NT Manager_1.0.apk`), runs the full `build` pipeline against it with the NDK, verifies the signed output, and uploads the JAR and APK as build artifacts.

## License

See `NOTICE`.
