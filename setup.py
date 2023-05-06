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
			for sp in path.glob('*'):
				if sp.name != 'ALL': shutil.rmtree(sp)
		else:
			os.remove(path)

def generateEncMsgs():
	print("Starting message encoding")
	charmap = 'assets/ALL/text/charmap.txt'
	from tools import msgenc
	for code in {'en', 'de', 'fr', 'es-SV', 'pt', 'pt-BR', 'it', 'sv-SE'}:
		input_h = f'include/translations/message_data_{code}.h'
		if code == 'es-SV': code = 'es'
		output_h = f'include/translations/message_data_{code}.enc.h'
		msgenc.do_enc(charmap, input_h, output_h)
	msgenc.do_enc(charmap, assetPath('text/message_data_staff.h'), assetPath('text/message_data_staff.enc.h'))
	print("Finished message encoding")

def addAdditionalChars():
	zapd = Path(zapdBinary())
	chars = []
	charsdir = str('assets/ALL/textures/nes_font_static')
	chars.extend(Path(charsdir).glob('*.i4.png'))
	mkdir(charsdir + '/generated')
	for char in chars:
		input_path = os.path.abspath(char)
		output_path = os.path.abspath(f'{charsdir}/generated/{os.path.splitext(os.path.basename(char))[0]}.inc.c')
		os.system(f'{zapd} btex -tt i4 -i {input_path} -o {output_path}')
	nes_remove = [] # Delete conflicting files
	nes_remove.extend(Path(assetPath('textures/nes_font_static')).glob('nes_font_static.*'))
	for file in nes_remove:
		try: os.remove(file)
		except OSError: pass

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
	generateEncMsgs()
	subprocess.check_call([sys.executable, str('tools/extract_missing_assets.py'), buildRom()])
	subprocess.check_call([sys.executable, str('tools/create_luts.py'), buildRom()])
	subprocess.check_call([sys.executable, str('tools/fix_mtx.py'), buildRom()])
	addAdditionalChars()

	print("Finished asset extraction and parsing")

def main():
	# Command Line Interface
	parser = argparse.ArgumentParser(description="Setup")
	parser.add_argument("-c", "--clean", help="Cleans environment before asset extraction", action="store_true", default=False)
	parser.add_argument("-p", "--props-only", help="Only sets project properties / options (does not extract assets)", action="store_true", default=False)
	parser.add_argument("-co", "--clean-only", help="Cleans environment without asset extraction", action="store_true", default=False)
	parser.add_argument("-b", "--buildRom", choices=validBuildOptions(), help="build rom config ex: EUR_MQD")
	parser.add_argument("-f", "--framerate", choices=['20', '25', '30', '40', '60', '120', '240'], help="game framerate", default='20')
	parser.add_argument("-m", "--enable-mouse", help="Enables mouse controls", action="store_true", default=True)
	parser.add_argument("--refresh-configs", help="Refreshes rom config files (do not use)", action="store_true", default=False)
	parser.add_argument("-o", "--organize-roms", help="Renames and moves roms to their proper location", action="store_true", default=False)
	parser.add_argument("-s", "--skip-organize-roms", help="Skip organizing roms", action="store_true", default=False)
	parser.add_argument("--run-msgenc", help="Run msgenc", action="store_true", default=False)
	parser.add_argument("--add-extra-chars", help="Adds new characters", action="store_true", default=False)
	
	args = parser.parse_args()
	
	if args.refresh_configs:
		calcRomHashes()
		exit(0)
		
	if args.organize_roms:
		organizeRoms()
		exit(0)
		
	if not args.props_only and not args.skip_organize_roms:
		organizeRoms()

	if args.buildRom:
		setBuildRom(args.buildRom)
	else:
		setBuildRom(findBuildRom())
		
	with open('vs/oot.props.src', 'r') as f:
		buffer = f.read()
	buffer = buffer.replace('#BUILD_ROM#', buildRom())
	defines = []
	defines.append('ENABLE_%sFPS' % args.framerate)

	if args.run_msgenc:
		generateEncMsgs()
		exit(0)

	if args.add_extra_chars:
		addAdditionalChars()
		exit(0)

	if args.enable_mouse:
		defines.append('ENABLE_MOUSE')

	if buildRom().lower()[-1] != 'd':
		defines.append('RETAIL')
	defines.append(re.sub(r'[^A-Z0-9_]+', '', buildRom()))
	defines.append('NATIVE')

	#buffer = re.sub(r'<PreprocessorDefinitions>.*</PreprocessorDefinitions>',  r'<PreprocessorDefinitions>%s</PreprocessorDefinitions>' % ';'.join(defines), buffer)
	buffer = buffer.replace('#DEFINES#', ';'.join(defines))

	with open('vs/oot.props', 'w') as f:
		f.write(buffer)

	if not args.props_only:
		if args.clean == True:
			clean()
			build()
		elif args.clean_only == True:
			clean()
		else:
			build()

if __name__ == "__main__":
	main()

