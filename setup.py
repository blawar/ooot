#!/usr/bin/env python3

import argparse
import os
from pathlib import Path
import shutil
import subprocess
import sys
import re
from tools.oot import *


def clean():
    # Clean build environment
    print("Cleaning build environment")

    # Build list of paths (files and folders) to delete
    paths = []
    # Assets
    paths.append(Path('assets/'))
    paths.append(Path('build/'))
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
    subprocess.check_call([sys.executable, str('tools/fixbaserom.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_baserom.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_assets.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_z64_variables.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/convert_assets.py'), buildRom()])
    mkdir(assetPath('text'))
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str(romPath('text/charmap.txt')), str(romPath('text/message_data.h')), str(assetPath('text/message_data.enc.h')), buildRom()])
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str(romPath('text/charmap.txt')), str(romPath('text/message_data_staff.h')), str(assetPath('text/message_data_staff.enc.h')), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_missing_assets.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/create_luts.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/fix_mtx.py'), buildRom()])

    print("Finished asset extraction and parsing")

def main():
    # Command Line Interface
    parser = argparse.ArgumentParser(description="Setup")
    parser.add_argument("-c", "--clean", help="Cleans environment before asset extraction", action="store_true", default=False)
    parser.add_argument("-co", "--clean-only", help="Cleans environment without asset extraction", action="store_true", default=False)
    parser.add_argument("-b", "--buildRom", choices=validBuildOptions(), help="build rom config ex: EUR_MQD")
    parser.add_argument("-f", "--framerate", choices=['20', '30', '60', '120', '240'], help="game framerate", default='20')
    parser.add_argument("-m", "--enable-mouse", help="Enables mouse controls", action="store_true", default=True)
    args = parser.parse_args()

    if args.buildRom:
        setBuildRom(args.buildRom)
    else:
        setBuildRom(findBuildRom())
        
    prop = Path('vs/oot.props')
    with open(prop, 'r') as f:
        buffer = f.read()
    buffer = re.sub(r'<buildrom>.*</buildrom>', r'<buildrom>%s</buildrom>' % buildRom(), buffer)
    defines = []
    defines.append('ENABLE_%sFPS' % args.framerate)

    if args.enable_mouse:
        defines.append('ENABLE_MOUSE')

    if buildRom().lower()[-1] != 'd':
        defines.append('RETAIL')
    defines.append(re.sub(r'[^A-Z0-9_]+', '', buildRom()))
    defines.append('NATIVE')
    defines.append('%(PreprocessorDefinitions)')
    buffer = re.sub(r'<PreprocessorDefinitions>.*</PreprocessorDefinitions>',  r'<PreprocessorDefinitions>%s</PreprocessorDefinitions>' % ';'.join(defines), buffer)

    with open(prop, 'w') as f:
        f.write(buffer)

    if args.clean == True:
        clean()
        build()
    elif args.clean_only == True:
        clean()
    else:
        build()

if __name__ == "__main__":
    main()

