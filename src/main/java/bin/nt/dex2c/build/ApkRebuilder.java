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
 * <p>Each original entry keeps its own compression method: stored entries
 * (e.g. {@code resources.arsc}, required uncompressed on API 30+) stay
 * stored and deflated entries stay deflated. The compiled libraries are
 * always stored uncompressed so zipalign can page-align them. Alignment is
 * repaired afterwards by zipalign.</p>
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
     * @param manifest      replacement {@code AndroidManifest.xml} bytes, or {@code null}
     * @throws IOException on I/O failure
     */
    static void rebuild(Path inApk, Path outApk, Map<String, Path> dexReplace,
            Map<String, Path> libs, String libName, byte[] manifest) throws IOException {
        byte[] buf = new byte[65536];
        try (ZipFile zin = new ZipFile(inApk.toFile());
             ZipOutputStream zout = new ZipOutputStream(Files.newOutputStream(outApk))) {
            Enumeration<? extends ZipEntry> en = zin.entries();
            while (en.hasMoreElements()) {
                ZipEntry e = en.nextElement();
                String name = e.getName();
                Path repl = name.matches("classes\\d*\\.dex") ? dexReplace.get(name) : null;
                boolean replaced = repl != null || (manifest != null && "AndroidManifest.xml".equals(name));
                ZipEntry out = new ZipEntry(name);
                out.setMethod(replaced ? ZipEntry.DEFLATED : e.getMethod());
                if (!replaced && e.getMethod() == ZipEntry.STORED) {
                    out.setSize(e.getSize());
                    out.setCrc(e.getCrc());
                }
                zout.putNextEntry(out);
                if (repl != null) {
                    Files.copy(repl, zout);
                } else if (manifest != null && "AndroidManifest.xml".equals(name)) {
                    zout.write(manifest);
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
                out.setMethod(ZipEntry.STORED);
                out.setSize(Files.size(l.getValue()));
                out.setCrc(crc32(l.getValue()));
                zout.putNextEntry(out);
                Files.copy(l.getValue(), zout);
                zout.closeEntry();
            }
        }
    }

    /** CRC-32 of a file, used for stored zip entries. */
    private static long crc32(Path p) throws IOException {
        java.util.zip.CRC32 c = new java.util.zip.CRC32();
        byte[] buf = new byte[65536];
        try (InputStream is = Files.newInputStream(p)) {
            int n;
            while ((n = is.read(buf)) > 0) {
                c.update(buf, 0, n);
            }
        }
        return c.getValue();
    }
}