package bin.nt.dex2c;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import org.junit.jupiter.api.Test;

import bin.nt.dex2c.build.BinaryXml;
import bin.nt.dex2c.build.ManifestPatcher;

/**
 * Round-trips the binary manifest of the real test APK through the patcher:
 * decode → set {@code android:name} on {@code application} → decode again.
 */
class ManifestPatcherTest {

    @Test
    void patchApplicationNameRoundTrip() throws Exception {
        Path apk = Paths.get("test", "NT Manager_1.0.apk");
        assertTrue(Files.isRegularFile(apk), "test APK missing: " + apk.toAbsolutePath());
        byte[] raw = BinaryXml.rawManifest(apk);
        BinaryXml.Manifest before = BinaryXml.read(raw);
        assertTrue(before.appName != null && !before.appName.isEmpty(),
                "the test APK manifest must declare an Application class");

        byte[] patched = ManifestPatcher.patchApplicationName(raw, "com.example.NativeLoader");
        BinaryXml.Manifest after = BinaryXml.read(patched);
        assertEquals("com.example.NativeLoader", after.appName);
        assertEquals(before.pkg, after.pkg, "package attribute must survive the rewrite");
    }
}