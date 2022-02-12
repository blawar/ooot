import os.path
from pathlib import Path
import re

def writeFile(path, buffer):
	with open(path, 'r', encoding="UTF-8") as f:
		if f.read() == buffer:
			return
			
	print('writing %s' % path)
	with open(path, 'w', encoding="UTF-8") as f:
		f.write(buffer)

dir = 'include/'
structs = {}
for path in Path(dir).rglob('*.h'):
	x = str(path).replace('\\', '/')
	#if 'ultra64' in x:
	#	continue
	#print(x)
	with open(x, 'r', encoding="UTF-8") as f:
		buffer = f.read().replace('\r', '')
		
	buffer = re.sub(r'typedef \s*struct\s*(\{[^\}]*\n\})\s*([A-Z0-9_]+)\s*;', r'struct \2 \1;', buffer, flags = re.I | re.S)
	buffer = re.sub(r'typedef \s*union\s*(\{[^\}]*\n\})\s*([A-Z0-9_]+)\s*;', r'union \2 \1;', buffer, flags = re.I | re.S)
	buffer = re.sub(r'typedef \s*enum\s*(\{[^\}]*\n\})\s*([A-Z0-9_]+)\s*;', r'enum \2 \1;', buffer, flags = re.I | re.S)
	
	buffer = re.sub(r'typedef \s*struct\s*([A-Za-z0-9_]*)\s*(\{[^\}]*\n\})\s*([A-Z0-9_]+)\s*;', r'struct \3 \2;', buffer, flags = re.I | re.S)
	
	buffer = buffer.replace('struct Gfx*', 'Gfx*')
	
	match = re.search(r'struct\s+([A-Za-z0-9_]+)[^A-Za-z0-9_]', buffer)
	
	if match:
		structs[match.group(1)] = 1

	writeFile(x, buffer)
exit(0)
files = []
for path in Path(dir).rglob('*.h'):
	x = str(path).replace('\\', '/')
	
	if 'ultra64' in x:
		continue
		
	files.append(x)
	
for path in Path('src').rglob('*.c'):
	x = str(path).replace('\\', '/')
	
	if 'ultra64' in x:
		continue
		
	files.append(x)
	
for x in files:
	with open(x, 'r', encoding="UTF-8") as f:
		buffer = f.read().replace('\r', '')
		buffer2 = buffer
		
		for struct, junk in structs.items():
			buffer = re.sub(r'(?!struct)(\s+)%s([^A-Za-z0-9_])' % struct, r'\1struct %s\2' % struct, buffer, flags = re.I)
		
		buffer = buffer.replace('struct struct ', 'struct ')
		'''
		if buffer != buffer2:
			print(buffer + '\n\n--------------------\n\n' + buffer2)
			exit(0)
		'''
		
		writeFile(x, buffer)
		