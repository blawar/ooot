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
    subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'libyaz0'])
    subprocess.check_call([sys.executable, str('tools/fixbaserom.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_baserom.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_assets.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/extract_z64_variables.py'), buildRom()])
    subprocess.check_call([sys.executable, str('tools/convert_assets.py'), buildRom()])
    mkdir(assetPath('text'))
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str(romPath('text/charmap.txt')), str(assetPath('text/message_data.h')), str(assetPath('text/message_data.enc.h')), buildRom()])
    subprocess.check_call([sys.executable, str('tools/msgenc.py'), str(romPath('text/charmap.txt')), str(assetPath('text/message_data_staff.h')), str(assetPath('text/message_data_staff.enc.h')), buildRom()])
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
    parser.add_argument("--disable-frizzle-cam", help="Disables R-Stick camera control", action="store_true", default=False)
    parser.add_argument("--disable-distance-culling", help="Disables culling distant objects", action="store_true", default=False)
    parser.add_argument("--enable-gyro", help="Enable gyro controls", action="store_true", default=False)
    parser.add_argument("--enable-debug-level-select", help="Enable debug level select on save 1", action="store_true", default=False)
    parser.add_argument("-t", "--text-speed", choices=['1', '2', '3', '4', '5', '10', '20'], help="Text scroll speed scaler", default='1')
    args = parser.parse_args()

    if args.buildRom:
        setBuildRom(args.buildRom)
    else:
        setBuildRom(findBuildRom())
        
    with open('vs/oot.props.src', 'r') as f:
        buffer = f.read()
    buffer = buffer.replace('#BUILD_ROM#', buildRom())
    defines = []
    defines.append('ENABLE_%sFPS' % args.framerate)
    defines.append('TEXT_SPEED_SCALER=%s' % args.text_speed)

    if args.enable_mouse:
        defines.append('ENABLE_MOUSE')

    if not args.disable_frizzle_cam:
        defines.append('FIZZLE_CAM')

    if args.disable_distance_culling:
        defines.append('NO_CULLING')

    if args.enable_gyro:
        defines.append('ENABLE_GYRO')

    if args.enable_debug_level_select:
        defines.append('ENABLE_DEBUG_LEVEL_SELECT')

    if buildRom().lower()[-1] != 'd':
        defines.append('RETAIL')
    defines.append(re.sub(r'[^A-Z0-9_]+', '', buildRom()))
    defines.append('NATIVE')

    #buffer = re.sub(r'<PreprocessorDefinitions>.*</PreprocessorDefinitions>',  r'<PreprocessorDefinitions>%s</PreprocessorDefinitions>' % ';'.join(defines), buffer)
    buffer = buffer.replace('#DEFINES#', ';'.join(defines))

    with open('vs/oot.props', 'w') as f:
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

