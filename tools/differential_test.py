#!/usr/bin/env python3
"""Static differential audit between the bundled Python reference and Java port.

This does not execute Android/NDK code. It compares the reference opcode table,
critical semantic handlers and the Java catalog/writer dispatch so regressions
are caught even on a host without an Android SDK.
"""
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
REF = ROOT / "reference/original-dex2c/dex2c"
JAVA = ROOT / "src/main/java/bin/nt/dex2c"

critical = {
    "const/4": "polymorphic constants",
    "filled-new-array": "result register",
    "move-result-object": "result register",
    "invoke-polymorphic": "API 26 method handles",
    "invoke-custom": "API 26 call sites",
    "add-int": "arithmetic",
    "add-int/2addr": "arithmetic",
    "add-int/lit8": "literal arithmetic",
    "if-eq": "reference identity",
}

ref_opcode = (REF / "opcode_ins.py").read_text(encoding="utf-8")
java_catalog = (JAVA / "opcode_ins/OpcodeCatalog.java").read_text(encoding="utf-8")
writer = (JAVA / "writer/CppWriter.java").read_text(encoding="utf-8")
ssa = (JAVA / "compiler/SsaBuilder.java").read_text(encoding="utf-8")

# Reference instruction set is an ordered Python list. Extract names from the
# actual list when possible; otherwise report the structural count only.
match = re.search(r"INSTRUCTION_SET\s*=\s*\[(.*?)\]\s*\n", ref_opcode, re.S)
ref_entries = re.findall(r"\n\s*([A-Za-z_][A-Za-z0-9_]*)\s*,", match.group(1)) if match else []
java_entries = re.findall(r'new Entry\(0x[0-9a-f]+,\s*"([^"]+)"', java_catalog, re.I)

print("dex2c differential audit")
print(f"reference instruction entries: {len(ref_entries)}")
print(f"java catalog entries:          {len(java_entries)}")

failed = 0
for opcode, reason in critical.items():
    present = opcode in java_catalog
    if not present:
        print(f"FAIL  {opcode:28} missing from Java catalog ({reason})")
        failed += 1
        continue
    token = opcode.replace('/', '\\?').replace('-', '-')
    # Java writer dispatch should mention the semantic family explicitly.
    family = opcode.split('/')[0]
    writer_ok = opcode in writer or family in writer or (opcode.startswith('move-result') and 'move-result' in writer)
    if not writer_ok:
        print(f"WARN  {opcode:28} catalogued but no obvious writer dispatch ({reason})")
    else:
        print(f"OK    {opcode:28} {reason}")

for needle in ("hackPolymorphicConstants", "IrVerifier.verify", "PushLocalFrame", "nt_resolve_class", "nt_resolve_method"):
    source = writer + ssa + (JAVA / "build/NdkProject.java").read_text(encoding="utf-8")
    if needle not in source:
        print(f"FAIL  required implementation marker missing: {needle}")
        failed += 1

# Reference-side semantic anchors.
for needle in ("hack_polymorphic_constant", "write_kill_local_reference", "invokecommon"):
    if needle not in ref_opcode and needle not in (REF / "compiler.py").read_text(encoding="utf-8") and needle not in (REF / "writer.py").read_text(encoding="utf-8"):
        print(f"WARN  reference anchor not found: {needle}")

print("RESULT:", "PASS" if failed == 0 else f"FAIL ({failed})")
sys.exit(1 if failed else 0)
