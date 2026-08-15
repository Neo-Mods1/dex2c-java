package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.Stream;

/**
 * Rewrites a DEX so every compiled method is declared {@code native} with no
 * body, and injects a {@code System.loadLibrary} call into the Application
 * class {@code <clinit>}.
 *
 * <p>Works on smali text via baksmali/smali, mirroring the reference dex2c
 * pipeline: compiled methods keep their (non-Dex2C) annotations but lose their
 * instruction bodies, so the runtime dispatches them into the generated
 * native library.</p>
 */
final class NativeMarker {

    private NativeMarker() {
    }

    /**
     * Marks compiled methods native and injects the library load.
     *
     * @param dexIn    the input DEX
     * @param dexOut   the rewritten DEX
     * @param smaliOut directory for the intermediate smali
     * @param compiled (class, name, descriptor) triples to mark native
     * @param appClass the Application class ({@code L...;}) or {@code null}
     * @param libName  the {@code System.loadLibrary} argument
     * @throws IOException on tool or I/O failure
     */
    static void mark(Path dexIn, Path dexOut, Path smaliOut, Set<String> compiled,
            String appClass, String libName) throws IOException {
        ToolRunner.javaMain("com.android.tools.smali.baksmali.Main",
                List.of("disassemble", "--api", "35", "--output", smaliOut.toString(), dexIn.toString()));
        try (Stream<Path> walk = Files.walk(smaliOut)) {
            List<Path> smali = walk.filter(p -> p.toString().endsWith(".smali")).collect(java.util.stream.Collectors.toList());
            for (Path f : smali) {
                edit(f, compiled, appClass, libName);
            }
        }
        ToolRunner.javaMain("com.android.tools.smali.smali.Main",
                List.of("assemble", "--api", "35", "--output", dexOut.toString(), smaliOut.toString()));
    }

    private static void edit(Path f, Set<String> compiled, String appClass, String libName) throws IOException {
        List<String> lines = Files.readAllLines(f, StandardCharsets.UTF_8);
        List<String> out = new ArrayList<>();
        String clsType = null;
        boolean inClinit = false;
        boolean injected = false;
        for (int i = 0; i < lines.size(); i++) {
            String line = lines.get(i);
            String t = line.trim();
            if (clsType == null && t.startsWith(".class")) {
                String[] parts = t.split("\\s+");
                clsType = parts[parts.length - 1];
                out.add(line);
                continue;
            }
            if (t.startsWith(".method")) {
                String last = t.substring(t.lastIndexOf(' ') + 1);
                int paren = last.indexOf('(');
                String name = paren >= 0 ? last.substring(0, paren) : last;
                String proto = paren >= 0 ? last.substring(paren) : "";
                boolean isClinit = "<clinit>".equals(name);
                boolean mark = clsType != null
                        && !isClinit
                        && !"<init>".equals(name)
                        && !t.contains(" native ")
                        && compiled.contains(clsType + name + proto);
                if (mark) {
                    out.add(line.replace(last, "native " + last));
                    i++;
                    while (i < lines.size()) {
                        String t2 = lines.get(i).trim();
                        if (".end method".equals(t2)) {
                            break;
                        }
                        if (t2.startsWith(".annotation") && !t2.contains("Dex2C")) {
                            out.add(lines.get(i));
                            i++;
                            while (i < lines.size() && !".end annotation".equals(lines.get(i).trim())) {
                                out.add(lines.get(i));
                                i++;
                            }
                            out.add(lines.get(i));
                        }
                        i++;
                    }
                    out.add(".end method");
                    continue;
                }
                out.add(line);
                inClinit = isClinit;
                continue;
            }
            if (inClinit) {
                if (t.startsWith(".registers") || t.startsWith(".locals")) {
                    String[] parts = t.split("\\s+");
                    int n;
                    try {
                        n = Integer.parseInt(parts[1]);
                    } catch (NumberFormatException e) {
                        n = 1;
                    }
                    out.add(n < 1 ? parts[0] + " 1" : line);
                    continue;
                }
                if (!injected && appClass != null && appClass.equals(clsType)
                        && !t.isEmpty() && !t.startsWith(".")) {
                    out.add(inject(libName));
                    injected = true;
                }
                if (".end method".equals(t)) {
                    if (!injected && appClass != null && appClass.equals(clsType)) {
                        out.add(inject(libName));
                        injected = true;
                    }
                    out.add(line);
                    inClinit = false;
                    continue;
                }
                out.add(line);
                continue;
            }
            out.add(line);
        }
        if (!injected && appClass != null && appClass.equals(clsType)) {
            String[] inj = inject(libName);
            out.add("");
            out.add(".method static constructor <clinit>()V");
            out.add("    .registers 1");
            out.add("");
            out.add(inj[0]);
            out.add(inj[1]);
            out.add("");
            out.add("    return-void");
            out.add(".end method");
        }
        Files.write(f, out, StandardCharsets.UTF_8);
    }

    private static String[] inject(String libName) {
        return new String[] {
                "    const-string v0, \"" + libName + "\"",
                "    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V"
        };
    }
}
