#!/usr/bin/python3

import os.path
from pathlib import Path
import sys

basedir = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__.replace('\\', '/'))), '../'))

magic = '// GENERATED'
includeHeader = '#include "asset_common.h"'
removeHeaders = ['#include "z64animation.h"', '#include "z64bgcheck.h"', '#include "asset_common.h"']
noLuts = ['gameplay_keep', 'gameplay_dangeon', 'gameplay_field']

def writeFile(path, buffer):
	with open(path, 'r') as f:
		if f.read() == buffer:
			return
			
	print('writing %s' % path)
	with open(path, 'w') as f:
		f.write(buffer)

def clean(buffer):
	lines = []
	for line in buffer.split('\n'):
		line = line.replace('\r', '').strip()
		
		if len(line) == 0 or line[0] == '#':
			continue
			
		if line.startswith('static void*') or line.startswith(magic):
			break
			
		lines.append(line)
		
	return '\n'.join(lines)
	
def cleanC(buffer):
	lines = []
	for line in buffer.split('\n'):
		line = line.replace('\r', '').strip()
			
		if line.startswith(magic):
			break
			
		lines.append(line)
		
	return '\n'.join(lines)

dir = 'assets/'
files = []
search = []

if len(sys.argv) > 1:
	for x in sys.argv[1:]:
		search.append(x.replace('\\', '/'))

for path in Path(dir).rglob('*.h'):
	x = str(path).replace('\\', '/')
	
	if len(search):
		for s in search:
			if s in x:
				files.append(path)
				break
	else:
		files.append(path)
	
for path in files:
	x = str(path).replace('\\', '/')
	skip = False

	if '/text/' in x:
		continue

	if '/audio/' in x:
		continue
		
	if len(x.split('/')) <= 2: # skip root assets directory files
		continue

	if '/overlays/' in x:
		skip = True

	name = path.name[0:-2]
	c_path = str(path)[0:-2] + '.c'

	lutVarName = name + '_lut'

	with open(path, 'r') as f:
		buffer = clean(f.read())
		
	map = []
	mapFull = []
	lutMap = []
		
	if not skip:
		isAllBytes = True
		for line in buffer.split('\n'):
			if not line.startswith('extern '):
				continue
			bits = line.split(' ')
			var = bits[-1]
			
			if bits[-2] != 'u8':
				isAllBytes = False
			if var[-3:] != '[];':
				#raise IOError('incorrect format: ' + var)
				map.append(var[0:-1])
			else:
				map.append(var[0:-3])
			mapFull.append(var[0:-1])
			
			if isAllBytes:
				lutMap.append(var[0:-3])
			#print(var[0:-3])
	
	result = '#pragma once\n'
	result += buffer + '\n\n%s\n\n' % magic
	
	if not skip:
		if mapFull[0][-2:] == '[]':
			startPtr = '(u8*)%s' % map[0]
		else:
			startPtr = '(u8*)&%s' % map[0]
		
		if mapFull[-1][-2:] == '[]':
			endPtr = '(u8*)%s' % map[-1]
		else:
			endPtr = '(u8*)&%s' % map[-1]
		
	endPtr = '(u8*)&_%sSegmentRomLastSymbol' % name
	
	if name not in noLuts and len(lutMap) > 0:
		result += 'static void* %s[] = {\n%s\n};\n\n' % (lutVarName, ',\n'.join(lutMap))
	
	result += 'extern u8 _%sSegmentRomLastSymbol;\n' % name
	if not skip:
		#result += '#define _%sSegmentStart (%s)\n' % (name, startPtr)
		#result += '#define _%sSegmentEnd (%s)\n' % (name, endPtr)
		result += '#define _%sSegmentRomStart (%s)\n' % (name, startPtr)
		result += '#define _%sSegmentRomEnd (%s)\n' % (name, endPtr)
	
	if skip:
		with open(c_path, 'r') as f:
			resultC = buffer = f.read()
	else:
		with open(c_path, 'r') as f:
			buffer = cleanC(f.read()).strip()
			resultC = buffer + '\n\n%s\n\n' % magic
			resultC += 'u8 _%sSegmentRomLastSymbol = 0;\n' % (name)
	
	#print(resultC)
	#break
	
	for i in removeHeaders:
		resultC = resultC.replace(i + '\n', '')
	
	if includeHeader not in resultC:
		resultC = resultC.replace('#include "ultra64.h"', '#include "ultra64.h"\n' + includeHeader)
		
	if '_scene.c' in c_path:
		resultC = resultC.replace('#include "z64cutscene.h"', '')
		resultC = resultC.replace('#include "ultra64.h"', '#include "ultra64.h"\n' + '#include "z64cutscene.h"')
	
	writeFile(path, result)
	writeFile(c_path, resultC)