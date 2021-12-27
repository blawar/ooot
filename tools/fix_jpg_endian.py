import os
from pathlib import Path
import re
import json

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

for path in Path('build/assets/scenes/').rglob('*.jpg.inc.c'):
	path = str(path)
	with open(path, 'r') as f:
		buffer = f.read().strip()
	buffer = re.sub(r'//.*$', '', buffer, flags = re.I | re.M)
		
	if buffer[0] == '#':
		continue

	b = []
	l = []
	
	for n in buffer.split(','):
		n = n.strip()
		if len(n) == 0:
			continue
		if n[0:2] != '0x':
			raise IOError('bad prefix: ' + n[0:2])
		
		if len(n) != 18:
			raise IOError('bad length: ' + n)

		b.append(n)
		
		n = n[2:]
		
		l.append('0x%s%s%s%s%s%s%s%s' % (n[14:16], n[12:14], n[10:12], n[8:10], n[6:8], n[4:6], n[2:4], n[0:2]))
		
	buffer = '#ifdef LITTLE_ENDIAN\n%s\n#else\n%s\n#endif' % (','.join(l), ','.join(b))
		
	writeFile(path, buffer)