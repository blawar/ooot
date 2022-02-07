#!/usr/bin/python3

import os
from pathlib import Path
from itertools import repeat
from tqdm import tqdm
from concurrent.futures import ThreadPoolExecutor

zapd = Path("tools/ZAPD/ZAPD.out")

def worker(path, type):
    # path without file extension
    rel = path.with_suffix('')
    # path without file extension plus build/ prefix
    out = 'build' / rel
    cmd = None
    # Use different commands depending on file type
    if type == 'jpg':
        cmd = f"{zapd} bren -i {rel}.jpg -o {out}.jpg.inc.c"
    elif type == 'bin':
        cmd = f"{zapd} bblb -i {rel}.bin -o {out}.bin.inc.c"
    elif type == 'png':
        assetType = Path(rel).suffix[1:]
        cmd = f"{zapd} btex -tt {assetType} -i {rel}.png -o {out}.inc.c"

    # Create folder before running of command. Otherwise it silently fails without converting
    Path.mkdir(out.parent, parents=True, exist_ok = True)
    os.system(cmd)

def main():
    # Gather all asset paths recursively in their respective lists
    pngs = []
    for path in Path('assets').rglob('*.png'):
        pngs.append(path)

    jpgs = []
    for path in Path('assets').rglob('*.jpg'):
        jpgs.append(path)

    bins = []
    for path in Path('assets').rglob('*.bin'):
        bins.append(path)

    # Multithreaded conversion of all assets with progress bar
    # Calls generalized worker by passing type
    thread_count = os.cpu_count() or 1
    print(f"Start converting {len(pngs) + len(jpgs) + len(bins)} assets with {thread_count} threads")
    with ThreadPoolExecutor(max_workers = thread_count) as executor:
        with tqdm(total = len(pngs) + len(jpgs) + len(bins)) as progress:
            for result in executor.map(worker, pngs, repeat('png')):
                progress.update()
            for result in executor.map(worker, jpgs, repeat('jpg')):
                progress.update()
            for result in executor.map(worker, bins, repeat('bin')):
                progress.update()

    print("Finished converting assets")

if __name__ == "__main__":
    main()
