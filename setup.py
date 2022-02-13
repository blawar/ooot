#!/usr/bin/env python3

import argparse
import os
from pathlib import Path
import shutil
import subprocess
import sys

def clean():
    # Clean build environment
    print("Cleaning build environment")

    # Build list of paths (files and folders) to delete
    paths = []
    # Assets
    paths.append(Path('baserom.z64'))
    paths.append(Path('baserom/'))
    paths.append(Path('build/'))
    paths.append(Path('assets/code/'))
    paths.append(Path('assets/misc/'))
    paths.append(Path('assets/objects/'))
    paths.append(Path('assets/overlays/'))
    paths.append(Path('assets/scenes/'))
    paths.append(Path('assets/textures/'))
    paths.extend(Path('assets/text').glob('*.h'))
    paths.extend(Path('src/code/').glob('*_assets.h'))
    # GlideN64
    paths.append(Path('GLideN64/projects/msvc/build'))
    paths.extend(Path('external/Win32/').glob('*GLide*'))
    paths.extend(Path('external/Win32/').glob('osal*'))
    # ooot
    paths.append(Path('vs/Debug/'))

    # Delete files and folders
    for path in paths:
        if path.exists() == False:
            continue
        elif path.is_dir():
            shutil.rmtree(path)
        else:
            os.remove(path)

def build():
    print("Starting asset extraction and parsing")
    # sys.executable points to python executable
    subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'tqdm'])
    subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'libyaz0'])
    subprocess.check_call([sys.executable, str('fixbaserom.py')])
    subprocess.check_call([sys.executable, str('extract_baserom.py')])
    subprocess.check_call([sys.executable, str('extract_assets.py')])
    subprocess.check_call([sys.executable, str('tools/extract_z64_variables.py')])
    subprocess.check_call([sys.executable, str('tools/convert_assets.py')])
    Path.mkdir(Path('build/assets/text'), parents=True, exist_ok = True)
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str('assets/text/charmap.txt'), str('assets/text/message_data.h'), str('build/assets/text/message_data.enc.h')])
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str('assets/text/charmap.txt'), str('assets/text/message_data_staff.h'), str('build/assets/text/message_data_staff.enc.h')])
    subprocess.check_call([sys.executable, str('tools/extract_missing_assets.py')])
    subprocess.check_call([sys.executable, str('tools/create_luts.py')])
    subprocess.check_call([sys.executable, str('tools/fix_mtx.py')])

    print("Finished asset extraction and parsing")

def main():
    # Command Line Interface
    parser = argparse.ArgumentParser(description="Setup")
    parser.add_argument("-c", "--clean", help="Cleans environment before asset extraction", action="store_true", default=False)
    parser.add_argument("-co", "--clean-only", help="Cleans environment without asset extraction", action="store_true", default=False)
    args = parser.parse_args()

    if args.clean == True:
        clean()
        build()
    elif args.clean_only == True:
        clean()
    else:
        build()

if __name__ == "__main__":
    main()

