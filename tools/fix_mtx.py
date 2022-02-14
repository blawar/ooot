import os
import re

def fix(path):
	with open(path, 'r', encoding="UTF-8") as f:
		buffer = f.read()
		
	result = re.sub(r'^(\s*)Mtx\s+([A-Za-z0-9_]*)\s*=\s*\{\s*([^}]*)\s*\};', r'\1Mtx \2 = MTX(\3);', buffer, flags=re.M)
	
	with open(path, 'w', encoding="UTF-8") as f:
		buffer = f.write(result)
		
	
#fix('assets/objects/object_link_child/object_link_child.c')
PATH = 'assets'
result = [os.path.join(dp, f) for dp, dn, filenames in os.walk(PATH) for f in filenames if os.path.splitext(f)[1] in ['.cpp', '.h']]
for f in result:
	try:
		fix(f)
	except:
		print('failed: %s' % str(f))