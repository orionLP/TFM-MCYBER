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

ALWYAS_PRESENT = ["._header_"]

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <opaque_calls.json>")
        sys.exit(1)

    json_path = sys.argv[1]
    with open(json_path, "r", encoding="utf-8") as f:
        data = json.load(f)
    
    techniques = [key for key in data['relations']]
    AVs = [key for key in data['surviving_files']]
    
    global_counter = Counter()
    for av_system in AVs:
        av_counter = Counter()
        for individual_technique in techniques:
            technique_counter = Counter()
            per_file = {}
            av_technique_dictionary = data['surviving_files'][av_system][individual_technique]
            for filename, section_lists in av_technique_dictionary.items():
                minimal_entries = compute_minimal_sets(section_lists)
                for entry in minimal_entries:
                    sections = tuple(sorted(entry['sections']))
                    global_counter[sections] += entry['count']
                    av_counter[sections] += entry['count']
                    technique_counter[sections] += entry['count']
            print(f'Counts for AV {av_system} and technique {individual_technique}')
            print(technique_counter)
            print(' ')
        print(f'Added counts accross all techniqeus for  av system {av_system}')
        print(av_counter)
        print(' ')
    print(f'Globally these are the counts')
    print(global_counter)

if __name__ == "__main__":
    main()
