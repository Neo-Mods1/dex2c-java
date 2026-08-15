# dex2c-cli

`dex2c-cli` is a standalone command-line compiler that translates Dalvik bytecode — from raw `.dex` files, APKs, or Zips — into JNI-ready C++ source code. Each method is lowered through a full IR pipeline (control-flow graph, SSA, register allocation) and emitted as a native function that can be built into a `.so` and loaded with `System.loadLibrary`.

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

## Testing

The test suite covers the IR pipeline (graph, SSA, phi cleanup) and the C++ writer end-to-end:

- `PortSmokeTest` — graph construction, RPO, dominators, trivial-phi removal
- `WriterSmokeTest` — a method lowered through the full pipeline to JNI C++

Continuous integration (`.github/workflows/build.yml`) builds the fat JAR, runs both smoke tests, compiles and inspects the real APK under `test/` (`NT Manager_1.0.apk`), and uploads the JAR as a build artifact.

## License

See `NOTICE`.
