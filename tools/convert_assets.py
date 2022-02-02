import os.path
from pathlib import Path
import os

basedir = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../'))

def cleanPath(path):
	return str(path).replace('\\', '/').replace('/', os.sep)

def getRelativePath(path):
	return cleanPath(path[len(basedir):].strip('/').strip('\\'))

def shellquote(s):
	return "'" + s.replace("'", "'\\''") + "'"
	
def ensureDirectory(path):
	try:
		p = Path(path)
		os.makedirs(p.parent)
	except:
		pass

try:
	os.makedirs(cleanPath('assets/build/text/'))
except:
	pass
		
zapd = None
for path in Path(os.path.abspath('tools\ZAPD')).rglob('ZAPD.out'):
	zapd = getRelativePath(os.path.abspath(str(path)))
	
if not zapd:
	raise IOError('ZAPD.out not found')

'''
searchdir = os.path.abspath('assets/xml')
for path in Path(searchdir).rglob('*.xml'):
	if 'gameplay_keep' not in str(path):
		continue
	rel = cleanPath(str(path)[len(searchdir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('assets/', rel)))
	ensureDirectory(out)
	cmd = '%s e -eh -i %s -b baserom\ -o %s -osf %s -gsf 1 -rconf tools\ZAPDConfigs\MqDbg\Config.xml' % (zapd, getRelativePath(str(path)), out, out)
	print(cmd)
	os.system(cmd)
'''

searchdir = os.path.abspath('assets')
for path in Path(searchdir).rglob('*.png'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	type = rel.split('.')[-1]
	ensureDirectory(out)
	cmd = '%s btex -eh -tt %s -i %s.png -o %s.inc.c' % (zapd, type, rel, out)
	print(cmd)
	os.system(cmd)
	
searchdir = os.path.abspath('assets')
for path in Path(searchdir).rglob('*.jpg'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	ensureDirectory(out)
	cmd = '%s bren -eh -i %s.jpg -o %s.inc.c' % (zapd, rel, out)
	print(cmd)
	os.system(cmd)
	
searchdir = os.path.abspath('assets')
for path in Path(searchdir).rglob('*.bin'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	ensureDirectory(out)
	cmd = '%s bblb -eh -i %s.bin -o %s.bin.inc.c' % (zapd, rel, out)
	print(cmd)
	os.system(cmd)
