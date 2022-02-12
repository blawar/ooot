#!/usr/bin/python3

import os
from pathlib import Path
from tqdm import tqdm
import re
import json

skipWords = ['extern', 'volatile']
newPath = 'include/def/'

cpp = True

def writeFile(path, buffer):
	try:
		with open(path, 'r', encoding="UTF-8") as f:
			if f.read() == buffer:
				return
	except:
		pass
			
	print('writing %s' % path)
	with open(path, 'w', encoding="UTF-8") as f:
		f.write(buffer)
		
def saveJson(file, v):
	with open(file, 'w') as f:
		f.write(json.dumps(v, indent=4, sort_keys=True))
		
def cleanType(t):	
	for bit in t.strip('*').split(' '):
		if bit != 'const':
			return bit.strip('*')
	return ''
	
structs = {'ActorContext': 1, 'ArenaNode': 1, 'Arena': 1}

for path in Path('include/').rglob('*.h'):
	path = str(path)
	
	#if 'z64global' not in path:
	#	continue
	
	#if 'speed' not in path:
	#	continue
	
	with open(path, 'r', encoding='UTF8') as f:
		buffer = f.read()
		
	buffer = re.sub('union\s*{[^\}]*}', '', buffer, flags = re.I | re.S)
		
	match = re.findall(r'typedef\s*struct\s*\{[^\}]*\}\s*([A-Z0-9_]+)\s*;', buffer, flags = re.I | re.S)
	
	if match:
		for m in match:
			structs[str(m)] = 1
			
	match = re.findall(r'typedef\s*struct\s*([A-Z0-9_]+)\s*\{[^\}]*\}', buffer, flags = re.I | re.S)
	
	if match:
		for m in match:
			structs[str(m)] = 1
			
			
	match = re.findall(r'struct\s*\{[^\}]*\}\s*([A-Z0-9_]+)\s*;', buffer, flags = re.I | re.S)
	
	if match:
		for m in match:
			structs[str(m)] = 1
			
	match = re.findall(r'struct\s*([A-Z0-9_]+)\s*\{[^\}]*\}', buffer, flags = re.I | re.S)
	
	if match:
		for m in match:
			structs[str(m)] = 1

x = list(structs.keys())
x.sort()
saveJson('structs.json', x)

with open('oldfuncs.h', 'r') as f:
	buffer = f.read()

symbols = {}

symbolsUse = {}
for line in buffer.split('\n'):
	line = line.strip()
	bits = line.split(' ')
	if bits[0] == 'const':
		offset = 1
	else:
		offset = 0
	datatype = bits[offset]
	
	rest = ' '.join(bits[offset+1:])
	
	callbits = rest.replace(')', '').replace(';', '').split('(')
	
	
	symbol = callbits[0].strip()
	args = []
	args2 = []
	argTypes = []
	for b in callbits[1].split(','):
		b = b.strip()
		
		if b == '':
			b = 'void'
		args.append(b)
		
		if not cpp and cleanType(b) in structs:
			args2.append('struct ' + b)
		else:
			args2.append(b)
			
		argTypes.append(cleanType(b))
	
	try:
		bits = line.split('(', 2)
		left = None
		right = None
		left = bits[0]

		#right = bits[1]
		#right = right.split(')', 2)[1]
		right = line.split(')')[-1]
		
		prototypeNew = '%s(%s)%s' % (left, ', '.join(args2), right)
		
		if not cpp and cleanType(prototypeNew) in structs:
			prototypeNew = 'struct ' + prototypeNew
		

		symbols[symbol] = {'type': datatype, 'source': [], 'refs': [], 'prototypeOrig': line, 'prototype': prototypeNew,'symbol': symbol, 'args': args, 'argTypes': argTypes}
		
		for arg in args:
			symbolsUse[cleanType(arg)] = 1
	except BaseException as e:
		print('line: ' + line)
		bits = line.split(')')[-1]
		print(left)
		print(right)
		print(bits)
		raise
	
#Gameplay_CameraSetAtEye
saveJson('symbols_func.json', symbols)
saveJson('symbols_use.json', list(symbolsUse.keys()))
#exit(0)

paths = []
for path in Path('src/').rglob('*.c'):
	path = str(path)
	
	if '/port/' in path.replace('\\', '/'):
		continue
	paths.append(str(path))
	
for path in Path('src/').rglob('*.cpp'):
	path = str(path)
	
	if '/port/' in path.replace('\\', '/'):
		continue
	paths.append(str(path))
	
for path in Path('assets/').rglob('*.c'):
	path = str(path)
	
	if '/port/' in path.replace('\\', '/'):
		continue
	paths.append(str(path))
	
for path in Path('assets/').rglob('*.cpp'):
	path = str(path)
	
	if '/port/' in path.replace('\\', '/'):
		continue
	paths.append(str(path))

saveJson('symbols_paths.json', paths)

j = 0
for path in tqdm(paths):
	with open(path, 'r', encoding='UTF8') as f:
		buffer = f.read()
	#print(path)
	#if path == "src\\code\\z_play.c" or 'play' in path:
	#	print('found in %s, %s' % (path, symbol))
	#	print(params['type'] + ' ' + symbol + '(')
	#	exit(0)
	for symbol, params in symbols.items():

				
		if (params['type'] + ' ' + symbol + '(') in buffer:
			params['source'].append(path)			
			
			if len(params['source']) > 1:
				print('more than one source! %s, %s' % (params['prototype'], ', '.join(params['source'])))

		if (symbol + '(') in buffer:
			params['refs'].append(path)
			
	#if j > 10:
	#	break
	j = j + 1 # ame-6905 wisconsin rav 4
	
saveJson('symbols_func.json', symbols)

#exit(0)

	
with open('variables_old.txt', 'r') as f:
	buffer = f.read()

var_symbols = {}

for line in buffer.split('\n'):
	line = line.strip()
	bits = line.split(' ')
	
	if len(bits) < 3:
		bits2 = bits[1].split('(')
		
		continue
		
		raise IOError('len to short: ' + line)
	
	offset = 0
	
	while(bits[offset] in skipWords):
		offset += 1
	
	if bits[offset] == 'const':
		offset += 1

	datatype = bits[offset]
	symbol = bits[offset+1].replace(';','(').split('(')[0].strip().split('[')[0]
	
	if symbol:
		var_symbols[symbol] = {'type': datatype, 'source': [], 'refs': [], 'prototype': line, 'symbol': symbol}

#exit(0)

j = 0
for path in tqdm(paths):
	with open(path, 'r', encoding='UTF8') as f:
		buffer = f.read()
	buffer = re.sub(r'^extern\s.*$', r'', buffer, flags=re.M).replace('(', ' ')
	#search = {}
	#for line in buffer.split(' '):
	#	search[line] = 1
		
	for symbol, params in var_symbols.items():
		#print('type: %s' % str(params['type']))
		#print(search)
		#exit(0)
		#print(('%s %s' % (params['type'], params['symbol'])))
		#if ('%s %s' % (params['type'], params['symbol'])) in search:
		if '[' in params['prototype']:
			extra = '['
		else:
			extra = ';'

		if ('%s %s' % (params['type'], params['symbol'])) in buffer:
			params['source'].append(path)
			#print('found "%s" %s in %s' % (params['symbol'], params['prototype'],  path))
			
			if len(params['source']) > 1:
				print('more than one source! %s, %s' % (params['prototype'], ', '.join(params['source'])))
			
		if params['symbol'] in buffer:
			params['refs'].append(path)
			
			
		#elif (symbol + '(') in buffer:
		#	params['refs'].append(path)
			
	#if j > 40:
	#	break
	j = j + 1

saveJson('symbols_var.json', var_symbols)
#exit(0)
fileMap = {}
for symbol, params in var_symbols.items():
	for f in params['source']:
		if f not in fileMap:
			fileMap[f] = [[], []]

		fileMap[f][1].append(params)
	

#print(fileMap)	
#print(var_symbols)


'''
for c_file, items in fileMap.items():
	buffer = '#pragma once\n\n'
	items[0].sort(key=lambda x: x['symbol'])
	items[1].sort(key=lambda x: x['symbol'])
	for param in items[1]:
		buffer += '%s\n' % param['prototype']
		
	writeFile(os.path.join(newPath, os.path.basename(c_file)[0:-2] + '_var.h'), buffer)
'''
#exit(0)
	
	
	
	
	
	
	

for symbol, params in symbols.items():
	for f in params['source']:
		if f not in fileMap:
			fileMap[f] = [[], []]
			
		fileMap[f][0].append(params)

saveJson('file_map.json', fileMap)
refs = {}

def getDefName(name):
	return 'INTERNAL_' + re.sub('[^A-Za-z0-9]+', '_', name).upper()

for c_file, items in fileMap.items():
	buffer = '#pragma once\n'
	
	bits = os.path.basename(c_file).split('.')
	bits[-1] = 'h'
	fileName = '.'.join(bits)
	
	items[0].sort(key=lambda x: x['symbol'])
	items[1].sort(key=lambda x: x['symbol'])
	
	ats = {}
	
	for param in items[0]: # functions
		for at in param["argTypes"]:
			ats[cleanType(at)] = 1
		ats[cleanType(param["type"])] = 1
		
	for param in items[1]: # variables
		ats[cleanType(param["type"])] = 1
		
	ctsa = ats.keys()
	sd = []
	for at in ctsa:
		ct = at
		if ct in structs and ct not in ('Mtx'):
			sd.append('struct %s;' % ct)
			
	if len(sd) > 0:
		buffer += '\n'.join(sd) + '\n'

	
	if len(items[1]) > 0:
		buffer += '\n'

		for param in items[1]:
			buffer += '%s\n' % param['prototype']
			
			for r in param['refs']:
				if r not in refs:
					refs[r] =[]
				if fileName not in refs[r]:
					refs[r].append(fileName)

	
	if len(items[0]) > 0:
		buffer += '\n'
		if not cpp:
			buffer += '#ifdef ' + getDefName(c_file) + '\n'
		
		for param in items[0]:
			buffer += '%s\n' % param['prototypeOrig'].replace('this', 'pthis')
			
			for r in param['refs']:
				if r not in refs:
					refs[r] =[]
					
				if fileName not in refs[r]:
					refs[r].append(fileName)
				
		if not cpp:
			buffer += '#else\n'
			
			for param in items[0]:
				buffer += '%s\n' % param['prototype']
				
			buffer += '#endif\n'
		
	writeFile(os.path.join(newPath, fileName), buffer)
	
with open('defRefMap.json', 'w') as f:
	f.write(json.dumps(refs, indent=4, sort_keys=True))

with open('defMap.json', 'w') as f:
	f.write(json.dumps(fileMap, indent=4, sort_keys=True))

	
	