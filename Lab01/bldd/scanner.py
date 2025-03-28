import os
import collections
from .elf_utils import get_architecture, get_needed_libraries


def scan_directory(scan_dir, target_libs):
    results = collections.defaultdict(lambda: collections.defaultdict(list))
    for root, _, files in os.walk(scan_dir):
        for file in files:
            filepath = os.path.join(root, file)
            if not os.path.isfile(filepath):
                continue
            try:
                with open(filepath, 'rb') as f:
                    if f.read(4) != b'\x7fELF':
                        print(f"Not an ELF file: {filepath}")
                        continue
                arch = get_architecture(filepath)
                if not arch or arch == 'unknown':
                    print(f"Unknown architecture for {filepath}")
                    continue
                needed = get_needed_libraries(filepath)
                for lib in needed:
                    if not target_libs or lib in target_libs:
                        results[arch][lib].append(filepath)
            except Exception:
                continue
    return results
