import os
from pathlib import Path
#from tqdm import tqdm
import re

basedir = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../'))

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

'''
find assets/ -iname '*.h' -exec sed -i -b 's/\(gsSP[A-Za-z]*\)(\(0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]\)/\1SEG(SEGMENT_ADDRESS(\2)/g' '{}' \;
find assets/ -iname '*.c' -exec sed -i -b 's/\(gsSP[A-Za-z]*\)(\(0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]\)/\1SEG(SEGMENT_ADDRESS(\2)/g' '{}' \;
find assets -iname '*.c' -exec sed -ib 's/gsDPLoadTextureBlock(\(0x[A-Za-z0-9]*\),/gsDPLoadTextureBlockSEG(SEGMENT_ADDRESS(\1),/g' "{}" \;
find assets -iname '*.c' -exec sed -ib 's/gsDPLoadMultiBlock(\(0x[A-Za-z0-9]*\),/gsDPLoadMultiBlockSEG(SEGMENT_ADDRESS(\1),/g' "{}" \;

-static Gfx sIntroVanishDList[17];
+static Gfx sIntroVanishDList[19];
'''

subs = {
	r'(gsSP[A-Za-z]*)\((0x0[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z][0-9A-Za-z])': r'\1SEG(SEGMENT_ADDRESS(\2)',
	r'gsDPLoadTextureBlock\((0x[A-Za-z0-9]*),': r'gsDPLoadTextureBlockSEG(SEGMENT_ADDRESS(\1),',
	r'gsDPLoadMultiBlock\((0x[A-Za-z0-9]*),': r'gsDPLoadMultiBlockSEG(SEGMENT_ADDRESS(\1),'
}

for path in Path(os.path.join(basedir, 'assets/')).rglob('*.c'):
	path = str(path)
	
	#if 'ovl_Boss_Sst.c' not in path:
	#	continue
	
	with open(path, 'r', encoding='UTF8') as f:
		buffer = f.read()
		
	for k, v in subs.items():
		buffer = re.sub(k, v, buffer)

	matches = re.findall('^(static )?Gfx\s*([A-Za-z0-9_]*)\s*\[\s*([0-9+]*)?\s*\]\s*=\s*{([^}]*)};', buffer, flags = re.I | re.S | re.M)
	#print(path)
	for m in matches:
		symbol = m[1]
		size = m[2]
		body = m[3]
		offset = 0
		
		if size == None or size == '':
			continue

		#print('%s %s' % (symbol, size))
		for line in body.split('\n'):
			if 'SEGMENT_ADDRESS' in line:
				offset += 1
				
		#print('%s %s => %d' % (symbol, size, offset))
		
		if offset > 0:
			buffer = re.sub('%s\s*\[[^]]*\]' % symbol, '%s[%d+%d]' % (symbol, int(size.split('+')[0]), offset), buffer)
		
	writeFile(path, buffer)