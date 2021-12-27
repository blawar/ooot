import os.path
from pathlib import Path

removeHeaders = ['#include "actor_common.h"', '#include "z64global.h"', '#include "sfx.h"', '#include "sequence.h"', '#include "z64effect.h"']

def writeFile(path, buffer):
	with open(path, 'r', encoding="UTF-8") as f:
		if f.read() == buffer:
			return
			
	print('writing %s' % path)
	with open(path, 'w', encoding="UTF-8") as f:
		f.write(buffer)

header = '#include "actor_common.h"'

dir = 'src/overlays/'
for path in Path(dir).rglob('*.c'):
	x = str(path).replace('\\', '/')
	#print(x)
	with open(x, 'r', encoding="UTF-8") as f:
		buffer = f.read().replace('\r', '')
		
	#if header not in buffer:
	for i in removeHeaders:
		buffer = buffer.replace(i + '\n', '')

	writeFile(x, header + '\n' + buffer)
		