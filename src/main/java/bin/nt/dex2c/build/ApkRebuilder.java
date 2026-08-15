package bin.nt.dex2c.build;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Enumeration;
import java.util.Map;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipOutputStream;

/**
 * Rebuilds an APK from its original entries, swapping in rewritten DEX files
 * and appending the compiled native libraries under {@code lib/<abi>/}.
 *
 * <p>Every non-DEX entry is copied byte-for-byte (including its compression
 * method); alignment is repaired later by zipalign.</p>
 */
final class ApkRebuilder {

    private ApkRebuilder() {
    }

    /**
     * Rebuilds {@code inApk} into {@code outApk}.
     *
     * @param inApk         the original APK
     * @param outApk        the output APK
     * @param dexReplace    dex entry name ({@code classes*.dex}) to new DEX file
     * @param libs          ABI to built {@code lib<name>.so}
     * @param libName       the {@code LOCAL_MODULE} name
     * @throws IOException on I/O failure
     */
    static void rebuild(Path inApk, Path outApk, Map<String, Path> dexReplace,
            Map<String, Path> libs, String libName) throws IOException {
        byte[] buf = new byte[65536];
        try (ZipFile zin = new ZipFile(inApk.toFile());
             ZipOutputStream zout = new ZipOutputStream(Files.newOutputStream(outApk))) {
            Enumeration<? extends ZipEntry> en = zin.entries();
            while (en.hasMoreElements()) {
                ZipEntry e = en.nextElement();
                String name = e.getName();
                Path repl = name.matches("classes\\d*\\.dex") ? dexReplace.get(name) : null;
                ZipEntry out = new ZipEntry(name);
                out.setMethod(ZipEntry.DEFLATED);
                zout.putNextEntry(out);
                if (repl != null) {
                    Files.copy(repl, zout);
                } else if (!e.isDirectory()) {
                    try (InputStream is = zin.getInputStream(e)) {
                        int n;
                        while ((n = is.read(buf)) > 0) {
                            zout.write(buf, 0, n);
                        }
                    }
                }
                zout.closeEntry();
            }
            for (Map.Entry<String, Path> l : libs.entrySet()) {
                String entryName = "lib/" + l.getKey() + "/lib" + libName + ".so";
                ZipEntry out = new ZipEntry(entryName);
                zout.putNextEntry(out);
                Files.copy(l.getValue(), zout);
                zout.closeEntry();
            }
        }
    }
}
