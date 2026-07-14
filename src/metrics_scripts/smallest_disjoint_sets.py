#!/usr/bin/env python3
"""
For each file in opaque_calls.json's surviving_files -> avast_free -> opaque_calls,
compute the "smallest disjoint" surviving section sets: the minimal antichain of
sets under the subset relation. I.e. a surviving set S is kept only if no other
surviving set for that same file is a proper subset of S (a smaller set that
already causes survival makes any superset of it redundant/non-minimal).

Example: if a file's surviving sets are
    [._header_], [._header_, .text], [.idata]
then [._header_, .text] is dropped because [._header_] (a subset of it) already
survives on its own. The result is [._header_] and [.idata].

Also computes a GLOBAL count: across all files, how many times each distinct
minimal section-combo appears (i.e. how many (file, occurrence) pairs reduce
down to that exact minimal set).

Usage:
    python3 compute_minimal_sections.py <opaque_calls.json> [output_path]

If output_path is omitted, writes to minimal_surviving_sections.json next to
the input file.
"""
import json
import sys
from collections import Counter
from pathlib import Path


def compute_minimal_sets(section_lists):
    """Given a list of section-lists (each a list of section-token strings)
    for one file, return:
        - minimal: list of (tuple_of_sections, count) for the minimal antichain,
                   sorted by size then alphabetically for stable output.
    Order within each combo is preserved from its first occurrence in
    section_lists.
    """
    # Track: frozenset -> (first-seen ordered tuple, occurrence count)
    counts = Counter()
    first_seen_order = {}
    for lst in section_lists:
        fs = frozenset(lst)
        counts[fs] += 1
        if fs not in first_seen_order:
            first_seen_order[fs] = tuple(lst)

    distinct_sets = list(counts.keys())

    minimal = []
    for s in distinct_sets:
        # s is minimal iff no other distinct set t is a proper subset of s
        if not any(t < s for t in distinct_sets if t is not s):
            minimal.append(s)

    # Stable, readable ordering: by size, then by the section names themselves
    minimal.sort(key=lambda s: (len(s), sorted(s)))

    return [
        {
            "sections": list(first_seen_order[s]),
            "count": counts[s],
        }
        for s in minimal
    ]


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <opaque_calls.json> [output_path]")
        sys.exit(1)

    json_path = sys.argv[1]
    if len(sys.argv) > 2:
        out_path = sys.argv[2]
    else:
        out_path = str(Path(json_path).with_name("minimal_surviving_sections.json"))

    with open(json_path, "r", encoding="utf-8") as f:
        data = json.load(f)

    opaque_calls = data["surviving_files"]["avast_free"]["opaque_calls"]

    per_file = {}
    global_counter = Counter()
    global_example = {}  # canonical key -> example ordered tuple, for readability

    for filename, section_lists in opaque_calls.items():
        minimal_entries = compute_minimal_sets(section_lists)
        per_file[filename] = minimal_entries

        for entry in minimal_entries:
            key = tuple(sorted(entry["sections"]))  # canonical, order-independent key
            global_counter[key] += entry["count"]
            if key not in global_example:
                global_example[key] = entry["sections"]

    # Build a JSON-friendly global counts section, sorted by count desc then
    # by combo size/name for stability.
    global_counts_list = [
        {
            "sections": global_example[key],
            "count": count,
        }
        for key, count in global_counter.items()
    ]
    global_counts_list.sort(key=lambda e: (-e["count"], len(e["sections"]), e["sections"]))

    result = {
        "per_file": per_file,
        "global_counts": global_counts_list,
    }

    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(result, f, indent=2)

    # Console summary
    print(f"Processed {len(opaque_calls)} files")
    for filename, entries in per_file.items():
        print(f"  {filename}: {len(entries)} minimal disjoint set(s)")
        for entry in entries:
            print(f"      {entry['sections']}  (count={entry['count']})")
    print()
    print(f"Top global minimal-set combos (by occurrence count):")
    for entry in global_counts_list[:15]:
        print(f"   {entry['count']:4d}x  {entry['sections']}")
    print()
    print(f"Wrote results to {out_path}")


if __name__ == "__main__":
    main()
