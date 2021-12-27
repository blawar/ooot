import os
from pathlib import Path
import re
import json

patch = '''Vec3s spot01_scenePathwayList_00036C[] = {
{0x01F1, 0x012C, 0x033F},
{0x01F1, 0x012C, 0x048B},
{0x00AC, 0x012C, 0x048B},
};

Vec3s spot01_scenePathwayList_000380[] = {
{0x048F, 0x0104, 0x0297},
{0x048F, 0x0104, 0x039C},
{0x041F, 0x0050, 0x0554},
{0x043D, 0x0050, 0x05BC},
{0x06A8, 0x00BD, 0x05C3},
{0x06CF, 0x00BD, 0x05A7},
};

Vec3s spot01_scenePathwayList_0003A4[] = {
{   1105,     80,     88 },
{    759,     80,    360 },
{   -110,      0,    376 },
{   -210,      0,      3 },
{   -725,    200,     -7 },
{   -765,    200,    -87 },
{   -675,    200,   -417 },
};

Path spot01_scenePathway_0003D0[] = {
{ 7, spot01_scenePathwayList_0003A4 },
{ 6, spot01_scenePathwayList_000380 },
{ 3, spot01_scenePathwayList_00036C },
};
'''

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
		
with open('assets/scenes/overworld/spot01/spot01_scene.c', 'r', encoding='UTF8') as f:
	buffer = f.read()

buffer = re.sub(r'^Path spot01_scenePathway_0003D0.*u8 spot01_scene_unaccounted_0003D8[^}]*\};', patch, buffer, flags = re.I | re.M | re.S )
writeFile('assets/scenes/overworld/spot01/spot01_scene.c', buffer)