package bin.nt.dex2c.build;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

/**
 * Minimal encoder for Android's binary XML manifest format.
 *
 * <p>Rebuilds the document with an {@code android:name} attribute set (or
 * updated) on the {@code application} element, appending the new strings to
 * the existing string pool. All other chunks are copied byte-for-byte so the
 * layout stays faithful to the input. The offset conventions mirror
 * {@link BinaryXml} (string offsets relative to the string data area).</p>
 */
public final class ManifestPatcher {

    private static final int CHUNK_STRING_POOL = 0x0001;
    private static final int CHUNK_START_ELEMENT = 0x0102;
    private static final int FLAG_UTF8 = 0x00000100;
    private static final int TYPE_STRING = 0x03;
    private static final String ANDROID_NS = "http://schemas.android.com/apk/res/android";

    private ManifestPatcher() {
    }

    /**
     * Ensures the {@code application} element carries
     * {@code android:name = className}.
     *
     * @param d         the binary manifest
     * @param className the Application class name (dotted, e.g. {@code bin.nt.main.NativeLoader})
     * @return the rewritten manifest
     * @throws IOException if the document is not a binary XML manifest
     */
    public static byte[] patchApplicationName(byte[] d, String className) throws IOException {
        int headerSize = u16(d, 2);
        int fileSize = u32(d, 4);
        if (u16(d, 0) != 0x0003 || headerSize < 8 || fileSize > d.length) {
            throw new IOException("Not a binary XML document");
        }

        Pool pool = null;
        int appPos = -1;
        int pos = fileSize < 0 ? d.length : headerSize;
        int end = fileSize;
        while (pos + 8 <= end) {
            int type = u16(d, pos);
            int size = u32(d, pos + 4);
            if (size < 8 || pos + size > end) {
                throw new IOException("Corrupt chunk at " + pos);
            }
            if (type == CHUNK_STRING_POOL) {
                pool = new Pool(d, pos, size);
            } else if (type == CHUNK_START_ELEMENT && pool != null) {
                int nameIdx = u32(d, pos + 20);
                if ("application".equals(strAt(pool, d, nameIdx))) {
                    appPos = pos;
                    break;
                }
            }
            pos += size;
        }
        if (pool == null) {
            throw new IOException("No string pool in manifest");
        }
        if (appPos < 0) {
            throw new IOException("No <application> element in manifest");
        }

        int androidNs = indexOf(pool, d, ANDROID_NS);
        int nameIdx = indexOf(pool, d, "name");
        int classIdx = indexOf(pool, d, className);
        int appendFrom = pool.count;
        if (androidNs < 0) {
            androidNs = appendFrom++;
        }
        if (nameIdx < 0) {
            nameIdx = appendFrom++;
        }
        if (classIdx < 0) {
            classIdx = appendFrom++;
        }

        String[] extra = new String[appendFrom - pool.count];
        int k = 0;
        if (androidNs >= pool.count) {
            extra[androidNs - pool.count] = ANDROID_NS;
        }
        if (nameIdx >= pool.count) {
            extra[nameIdx - pool.count] = "name";
        }
        if (classIdx >= pool.count) {
            extra[classIdx - pool.count] = className;
        }

        int newStrData = pool.stringDataSize + appendedSize(extra, (pool.flags & FLAG_UTF8) != 0);
        int newStringsStart = 28 + 4 * appendFrom + 4 * pool.styles;
        int newChunkSize = newStringsStart + newStrData + pool.styleDataSize;

        int attrStart = u16(d, appPos + 24);
        int attrBase = appPos + u16(d, appPos + 2) + attrStart;
        int attrCount = u16(d, appPos + 28);
        int found = -1;
        for (int i = 0; i < attrCount; i++) {
            int a = attrBase + i * 20;
            if (u32(d, a) == androidNs && u32(d, a + 4) == nameIdx) {
                found = i;
                break;
            }
        }
        int newAttrCount = attrCount + (found < 0 ? 1 : 0);
        int newTagSize = u32(d, appPos + 4) + (found < 0 ? 20 : 0);

        int newFileSize = fileSize - pool.chunkSize - u32(d, appPos + 4) + newChunkSize + newTagSize;

        ByteArrayOutputStream out = new ByteArrayOutputStream(newFileSize);
        writeU16(out, 0x0003);
        writeU16(out, headerSize);
        writeU32(out, newFileSize);

        writeChunks(out, d, pool, androidNs, nameIdx, classIdx, newStringsStart, newStrData,
                appendFrom, extra, fileSize, appPos, newTagSize, newAttrCount, attrBase, found);
        byte[] r = out.toByteArray();
        if (r.length != newFileSize) {
            throw new IOException("Encoder size mismatch: " + r.length + " != " + newFileSize
                    + " (flags=0x" + Integer.toHexString(pool.flags)
                    + " count=" + pool.count + " styles=" + pool.styles
                    + " header=" + pool.headerSize + " stringsStart=" + pool.stringsStart
                    + " stylesStart=" + pool.stylesStart + " strData=" + pool.stringDataSize
                    + " styleData=" + pool.styleDataSize + " newChunk=" + newChunkSize
                    + " newStrData=" + newStrData + " appended="
                    + appendedSize(extra, (pool.flags & FLAG_UTF8) != 0) + ")");
        }
        return r;
    }

    private static void writeChunks(ByteArrayOutputStream out, byte[] d, Pool pool,
            int androidNs, int nameIdx, int classIdx, int newStringsStart, int newStrData,
            int newCount, String[] extra, int fileSize, int appPos, int newTagSize,
            int newAttrCount, int attrBase, int found) throws IOException {
        int pos = u16(d, 2);
        int end = fileSize;
        boolean poolDone = false;
        boolean appDone = false;
        while (pos < end) {
            int type = u16(d, pos);
            int size = u32(d, pos + 4);
            if (!poolDone && pos == pool.chunkPos) {
                writePool(out, d, pool, newStringsStart, newStrData, newCount, extra);
                poolDone = true;
            } else if (!appDone && pos == appPos) {
                writeTag(out, d, appPos, newTagSize, newAttrCount, attrBase, found,
                        androidNs, nameIdx, classIdx, extra.length, pool.count);
                appDone = true;
            } else {
                out.write(d, pos, size);
            }
            pos += size;
        }
        if (!poolDone || !appDone) {
            throw new IOException("Internal chunk walk failed");
        }
    }

    /** Rebuilds the string pool with the appended entries. */
    private static void writePool(ByteArrayOutputStream out, byte[] d, Pool pool,
            int newStringsStart, int newStrData, int newCount, String[] extra) throws IOException {
        writeU16(out, CHUNK_STRING_POOL);
        writeU16(out, pool.headerSize);
        int chunkSize = newStringsStart + newStrData + pool.styleDataSize;
        writeU32(out, chunkSize);
        writeU32(out, newCount);
        writeU32(out, pool.styles);
        writeU32(out, pool.flags);
        writeU32(out, newStringsStart);
        writeU32(out, newStringsStart + newStrData);

        int offBase = pool.chunkPos + pool.headerSize;
        for (int i = 0; i < pool.count; i++) {
            writeU32(out, u32(d, offBase + 4 * i));
        }
        int acc = pool.stringDataSize;
        for (int i = pool.count; i < newCount; i++) {
            writeU32(out, acc);
            acc += encodedSize(extra[i - pool.count], (pool.flags & FLAG_UTF8) != 0);
        }
        for (int i = 0; i < pool.styles; i++) {
            writeU32(out, u32(d, offBase + 4 * pool.count + 4 * i));
        }

        int stringDataStart = pool.chunkPos + pool.stringsStart;
        out.write(d, stringDataStart, pool.stringDataSize);
        writeAppended(out, extra, (pool.flags & FLAG_UTF8) != 0);
        int styleDataStart = pool.chunkPos + pool.stylesStart;
        out.write(d, styleDataStart, pool.styleDataSize);
    }

    /** Writes the {@code application} start tag with the name attribute set. */
    private static void writeTag(ByteArrayOutputStream out, byte[] d, int pos,
            int newTagSize, int newAttrCount, int attrBase, int found,
            int androidNs, int nameIdx, int classIdx, int extraCount, int oldCount) throws IOException {
        if (attrBase - pos < 30) {
            throw new IOException("Unexpected <application> start tag layout");
        }
        out.write(d, pos, 8);
        writeU32(out, newTagSize);
        out.write(d, pos + 12, 16);
        writeU16(out, newAttrCount);
        out.write(d, pos + 30, attrBase - pos - 30);
        int attrCount = u16(d, pos + 28);
        for (int i = 0; i < attrCount; i++) {
            writeAttr(out, d, attrBase + i * 20, -1, -1, i == found ? classIdx : -1);
        }
        if (found < 0) {
            writeAttrNew(out, androidNs, nameIdx, classIdx);
        }
    }

    /** Copies an attribute entry, optionally replacing its string value index. */
    private static void writeAttr(ByteArrayOutputStream out, byte[] d, int a,
            int nsOverride, int nameOverride, int valueOverride) throws IOException {
        if (valueOverride >= 0) {
            int ns = nsOverride >= 0 ? nsOverride : u32(d, a);
            int name = nameOverride >= 0 ? nameOverride : u32(d, a + 4);
            writeU32(out, ns);
            writeU32(out, name);
            writeU32(out, u32(d, a + 8));
            out.write(d, a + 12, 2);
            out.write(d, a + 14, 1);
            out.write(d, a + 15, 1);
            writeU32(out, valueOverride);
        } else {
            out.write(d, a, 20);
        }
    }

    /** Writes a fresh attribute entry: {@code android:name = <className>}. */
    private static void writeAttrNew(ByteArrayOutputStream out, int ns, int name, int value)
            throws IOException {
        writeU32(out, ns);
        writeU32(out, name);
        writeU32(out, 0xFFFFFFFF);
        writeU16(out, 8);
        out.write(0);
        out.write(TYPE_STRING);
        writeU32(out, value);
    }

    private static int appendedSize(String[] extra, boolean utf8) {
        int n = 0;
        for (String s : extra) {
            n += encodedSize(s, utf8);
        }
        return n;
    }

    private static int encodedSize(String s, boolean utf8) {
        return pad4(encodedLen(s, utf8) + (utf8 ? 1 : 2));
    }

    private static void writeAppended(ByteArrayOutputStream out, String[] extra, boolean utf8)
            throws IOException {
        for (String s : extra) {
            if (utf8) {
                byte[] body = s.getBytes(StandardCharsets.UTF_8);
                writeLen(out, body.length);
                out.write(body);
                out.write(0);
            } else {
                writeU16(out, s.length());
                out.write(s.getBytes(StandardCharsets.UTF_16LE));
                writeU16(out, 0);
            }
            while ((out.size() & 3) != 0) {
                out.write(0);
            }
        }
    }

    private static int encodedLen(String s, boolean utf8) {
        int body = s.getBytes(StandardCharsets.UTF_8).length;
        return utf8 ? body + (body >= 0x80 ? 2 : 1) : s.length() * 2 + 2;
    }

    private static int pad4(int n) {
        return (n + 3) & ~3;
    }

    private static void writeLen(ByteArrayOutputStream out, int len) throws IOException {
        if (len >= 0x80) {
            out.write(0x80 | (len >> 8));
            out.write(len & 0xFF);
        } else {
            out.write(len);
        }
    }

    private static String strAt(Pool pool, byte[] d, int idx) {
        if (idx < 0 || idx >= pool.count) {
            return null;
        }
        int s = pool.chunkPos + pool.stringsStart + u32(d, pool.chunkPos + pool.headerSize + 4 * idx);
        return BinaryXml.readString(d, s, (pool.flags & FLAG_UTF8) != 0);
    }

    private static int indexOf(Pool pool, byte[] d, String s) {
        for (int i = 0; i < pool.count; i++) {
            if (s.equals(strAt(pool, d, i))) {
                return i;
            }
        }
        return -1;
    }

    /** Decoded string pool header and layout. */
    private static final class Pool {
        final int chunkPos;
        final int chunkSize;
        final int headerSize;
        final int count;
        final int styles;
        final int flags;
        final int stringsStart;
        final int stylesStart;
        final int stringDataSize;
        final int styleDataSize;

        Pool(byte[] d, int pos, int size) {
            chunkPos = pos;
            chunkSize = size;
            headerSize = u16(d, pos + 2);
            flags = u32(d, pos + 16);
            count = u32(d, pos + 8);
            styles = u32(d, pos + 12);
            stringsStart = u32(d, pos + 20);
            stylesStart = u32(d, pos + 24);
            int afterStrings = pos + stringsStart;
            int total = pos + size;
            int styleArea = styles > 0 ? pos + stylesStart : total;
            styleDataSize = total - styleArea;
            stringDataSize = styleArea - afterStrings;
        }
    }

    private static int u16(byte[] d, int p) {
        return (d[p] & 0xFF) | ((d[p + 1] & 0xFF) << 8);
    }

    private static int u32(byte[] d, int p) {
        return (d[p] & 0xFF) | ((d[p + 1] & 0xFF) << 8) | ((d[p + 2] & 0xFF) << 16)
                | ((d[p + 3] & 0xFF) << 24);
    }

    private static void writeU16(ByteArrayOutputStream out, int v) {
        out.write(v & 0xFF);
        out.write((v >> 8) & 0xFF);
    }

    private static void writeU32(ByteArrayOutputStream out, int v) {
        out.write(v & 0xFF);
        out.write((v >> 8) & 0xFF);
        out.write((v >> 16) & 0xFF);
        out.write((v >> 24) & 0xFF);
    }
}