import os
import json
import re

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

with open('defRefMap.json', 'r') as f:
	refs = json.load(f)
	
def getDefName(name):
	return 'INTERNAL_' + re.sub('[^A-Za-z0-9]+', '_', name).upper()
	
def cleanC(path, incs):
	with open(path, 'r', encoding='UTF8') as f:
		buffer = f.read().replace('\r', '')
		
	lines = []
	newLines = []
	headerPos = 0
	for line in buffer.split('\n'):
		if line.startswith('#include "def/') or line.startswith('#define INTERNAL_'):
			continue
		newLines.append(line)
		
		if line.startswith('#include '):
			if len(newLines) - headerPos < 20:
				headerPos = len(newLines)
		
	buffer = ('#define %s\n' % getDefName(path)) + '\n'.join(newLines[0:headerPos] + incs + newLines[headerPos:])
	#print(buffer)
	#exit(0)
	return buffer
	
for src, lst in refs.items():
	print(src)
	lst.sort()
	
	incs = []
	for i in lst:
		incs.append('#include "def/%s"' % i)
		
	#if len(incs) > 0:
	#	incs.append('')
	buffer = cleanC(src, incs)
	#print(buffer)
	#break
	writeFile(src, buffer)