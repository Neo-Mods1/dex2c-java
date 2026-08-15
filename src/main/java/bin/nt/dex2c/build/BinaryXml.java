package bin.nt.dex2c.build;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * Minimal reader for Android's binary XML manifest format.
 *
 * <p>Extracts only what the build needs: the {@code package} attribute of the
 * root element and the {@code android:name} attribute of the
 * {@code application} element, both of which may be required to locate the
 * Application class for {@code System.loadLibrary} injection.</p>
 */
public final class BinaryXml {

    private static final int CHUNK_STRING_POOL = 0x0001;
    private static final int CHUNK_START_ELEMENT = 0x0102;
    private static final int FLAG_UTF8 = 0x00000100;
    private static final int TYPE_STRING = 0x03;
    private static final String ANDROID_NS = "http://schemas.android.com/apk/res/android";

    /** Parsed manifest facts. */
    public static final class Manifest {
        public final String pkg;
        public final String appName;

        Manifest(String pkg, String appName) {
            this.pkg = pkg;
            this.appName = appName;
        }
    }

    private BinaryXml() {
    }

    /**
     * Reads the manifest of an APK.
     *
     * @param apk the APK file
     * @return the parsed facts
     * @throws IOException if the manifest is missing or unreadable
     */
    public static Manifest read(Path apk) throws IOException {
        try (ZipFile z = new ZipFile(apk.toFile())) {
            ZipEntry e = z.getEntry("AndroidManifest.xml");
            if (e == null) {
                throw new IOException("No AndroidManifest.xml in " + apk);
            }
            byte[] data;
            try (InputStream is = z.getInputStream(e)) {
                data = is.readAllBytes();
            }
            return parse(data);
        }
    }

    private static Manifest parse(byte[] d) throws IOException {
        int pos = u16(d, 0) == 0x0003 ? u16(d, 2) : 8;
        if (u16(d, pos) != CHUNK_STRING_POOL) {
            throw new IOException("Manifest is not a binary XML document");
        }
        String[] pool = readStringPool(d, pos);
        pos += u32(d, pos + 4);
        String pkg = null;
        String app = null;
        while (pos + 8 <= d.length) {
            int type = u16(d, pos);
            int size = u32(d, pos + 4);
            if (size < 8) {
                break;
            }
            if (type == CHUNK_START_ELEMENT) {
                int ns = u32(d, pos + 16);
                int nameIdx = u32(d, pos + 20);
                int attrStart = u16(d, pos + 24);
                int attrSize = u16(d, pos + 26);
                int attrCount = u16(d, pos + 28);
                String el = str(pool, nameIdx);
                int aoff = pos + 16 + attrStart;
                for (int i = 0; i < attrCount && aoff + 20 <= d.length; i++) {
                    int ans = u32(d, aoff);
                    int aname = u32(d, aoff + 4);
                    int raw = u32(d, aoff + 8);
                    int atype = d[aoff + 14] & 0xFF;
                    int adata = u32(d, aoff + 16);
                    String attr = str(pool, aname);
                    if (attr != null) {
                        if ("manifest".equals(el) && "package".equals(attr) && pkg == null) {
                            pkg = stringValue(pool, atype, adata, raw);
                        } else if ("application".equals(el) && "name".equals(attr) && app == null) {
                            String attrNs = ans == -1 ? null : str(pool, ans);
                            if (attrNs == null || attrNs.contains(ANDROID_NS)) {
                                app = stringValue(pool, atype, adata, raw);
                            }
                        }
                    }
                    aoff += attrSize == 0 ? 20 : attrSize;
                }
            }
            pos += size;
        }
        return new Manifest(pkg, app);
    }

    private static String stringValue(String[] pool, int atype, int adata, int raw) {
        if (atype == TYPE_STRING) {
            return str(pool, adata);
        }
        return raw != -1 ? str(pool, raw) : null;
    }

    private static String[] readStringPool(byte[] d, int start) {
        int count = u32(d, start + 8);
        int flags = u32(d, start + 16);
        int stringsStart = u32(d, start + 20);
        String[] out = new String[count];
        for (int i = 0; i < count; i++) {
            int off = u32(d, start + 28 + 4 * i);
            int s = start + stringsStart + off;
            if ((flags & FLAG_UTF8) != 0) {
                int[] l16 = utfLen(d, s);
                s += l16[1];
                int[] l8 = utfLen(d, s);
                s += l8[1];
                out[i] = new String(d, s, l8[0], StandardCharsets.UTF_8);
            } else {
                int n = u16(d, s);
                s += 2;
                StringBuilder sb = new StringBuilder(n);
                for (int j = 0; j < n; j++) {
                    sb.append((char) u16(d, s + 2 * j));
                }
                out[i] = sb.toString();
            }
        }
        return out;
    }

    /** Decodes a variable-length UTF-8 string length; returns {@code {value, bytes}}. */
    private static int[] utfLen(byte[] d, int p) {
        int v = d[p] & 0xFF;
        if ((v & 0x80) == 0) {
            return new int[] {v, 1};
        }
        return new int[] {((v & 0x7F) << 8) | (d[p + 1] & 0xFF), 2};
    }

    private static String str(String[] pool, int idx) {
        if (idx < 0 || idx >= pool.length) {
            return null;
        }
        return pool[idx];
    }

    private static int u16(byte[] d, int p) {
        return (d[p] & 0xFF) | ((d[p + 1] & 0xFF) << 8);
    }

    private static int u32(byte[] d, int p) {
        return (d[p] & 0xFF) | ((d[p + 1] & 0xFF) << 8) | ((d[p + 2] & 0xFF) << 16) | ((d[p + 3] & 0xFF) << 24);
    }
}
