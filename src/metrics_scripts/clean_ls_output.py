"""
Rebuilds opaque_calls.json's surviving_files -> avast_free -> opaque_calls section
using the files listed in output_ls and the section tokens declared in
file_headers -> opaque_calls.

Usage:
    python3 process_opaque_calls.py <path_to_output_ls> <path_to_opaque_calls.json> [output_path]

If output_path is omitted, opaque_calls.json is overwritten in place (a .bak
backup of the original is written alongside it first).
"""
import json
import re
import sys
from pathlib import Path


def parse_ls_filenames(ls_path: str):
    """Extract just the filenames from an `ls -la` style listing, skipping
    the 'total NNN' header line and the '.' / '..' entries."""
    filenames = []
    with open(ls_path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.rstrip("\n")
            if not line or line.startswith("total "):
                continue
            parts = line.split(None, 8)  # ls -l has 9 whitespace-separated fields, last is name
            if len(parts) < 9:
                continue
            name = parts[8]
            if name in (".", ".."):
                continue
            filenames.append(name)
    return filenames


def tokenize_suffix(suffix: str, tokens: list):
    """Greedily break `suffix` into a list of tokens drawn from `tokens`,
    preserving the order in which they appear in the filename.
    Returns None if the suffix can't be fully consumed."""
    result = []
    i = 0
    n = len(suffix)
    while i < n:
        matched = False
        for tok in tokens:
            if suffix.startswith(tok, i):
                result.append(tok)
                i += len(tok)
                matched = True
                break
        if not matched:
            return None  # leftover text we don't recognize
    return result


def build_surviving_entries(filenames, file_headers_opaque_calls):
    """For each base filename (e.g. 'output_0.exe') in file_headers, find every
    occurrence among `filenames` that starts with that base name, and record
    the parsed list of appended section tokens for each occurrence."""
    # Sort base names longest-first so e.g. 'output_10.exe' isn't matched by
    # a shorter base name that happens to be a prefix of it (defensive; in
    # practice these names are already unambiguous because of the trailing
    # '.exe').
    bases = sorted(file_headers_opaque_calls.keys(), key=len, reverse=True)

    result = {}
    unmatched = []

    for fname in filenames:
        base_match = None
        for base in bases:
            if fname.startswith(base):
                base_match = base
                break
        if base_match is None:
            continue  # not one of our tracked files, ignore

        suffix = fname[len(base_match):]
        tokens = file_headers_opaque_calls[base_match]

        if suffix == "":
            # The unmodified/original file with no sections zeroed out.
            result.setdefault(base_match, []).append([])
            continue

        parsed = tokenize_suffix(suffix, tokens)
        if parsed is None:
            unmatched.append(fname)
            continue

        result.setdefault(base_match, []).append(parsed)

    return result, unmatched


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <output_ls> <opaque_calls.json> [output_path]")
        sys.exit(1)

    ls_path = sys.argv[1]
    json_path = sys.argv[2]
    out_path = sys.argv[3] if len(sys.argv) > 3 else json_path

    with open(json_path, "r", encoding="utf-8") as f:
        data = json.load(f)

    file_headers_opaque_calls = data["file_headers"]["opaque_calls"]

    filenames = parse_ls_filenames(ls_path)
    print(f"Parsed {len(filenames)} filenames from {ls_path}")

    new_entries, unmatched = build_surviving_entries(filenames, file_headers_opaque_calls)

    if unmatched:
        print(f"WARNING: {len(unmatched)} filenames could not be tokenized against "
              f"their base file's known sections. First few:")
        for u in unmatched[:10]:
            print("   ", u)

    # Replace the surviving_files -> avast_free -> opaque_calls dict entirely
    # with the freshly computed entries.
    data["surviving_files"]["avast_free"]["opaque_calls"] = new_entries

    # Back up the original file before overwriting, if we're writing in place.
    if out_path == json_path:
        backup_path = json_path + ".bak"
        Path(json_path).replace(backup_path) if False else None  # no-op guard
        # Actually just copy original content we already loaded before modifying,
        # by re-reading from disk (safer than moving mid-flight).
        import shutil
        shutil.copyfile(json_path, backup_path)
        print(f"Backed up original to {backup_path}")

    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2)

    print(f"Wrote updated JSON to {out_path}")
    print(f"surviving_files.avast_free.opaque_calls now has {len(new_entries)} file keys:")
    for k, v in new_entries.items():
        print(f"   {k}: {len(v)} surviving instance(s)")


if __name__ == "__main__":
    main()
