import sys
import os
import os.path
import json
from pathlib import Path

_assetPath = None
_buildRom = None
_conf = None

class ConfSection:
	def __init__(self, j):
		self.offset = 0
		self.size = 0
		
		try:
			self.offset = int(j['offset'], 16)
			self.size = int(j['size'], 16)
		except:
			pass
			
class ConfRom:
	def __init__(self, j):
		try:
			self.UNCOMPRESSED_SIZE = int(j['UNCOMPRESSED_SIZE'], 16)
		except:
			pass
			
		try:
			self.FILE_TABLE_OFFSET = int(j['FILE_TABLE_OFFSET'], 16)
		except:
			pass
			
		self.hash_md5 = j['hash_md5']
		self.FILE_NAMES = j['FILE_NAMES']

class ConfSections:
	def __init__(self):
		pass

class Conf:
	def __init__(self, path):
		self.path = path
		self.sections = ConfSections()
		
		with open(path, 'r') as f:
			j = json.load(f)
		for k,v in j['sections'].items():
			self.sections.__dict__[k] = ConfSection(v)
		self.rom = ConfRom(j['rom'])
		
		
def config():
	global _conf
	if _conf is None:
		_conf = Conf(romPath('config.json'))
	return _conf

def fixSlashPath(path):
	return str(Path(path))
	
def validBuildOptions():
	r = []
	base = 'roms'
	for f in os.listdir(Path(base)):
		if os.path.exists(Path(base).joinpath(f).joinpath('zapd/Config.xml')):
			r.append(f)
	return r

def setBuildRom(p):
	global _buildRom
	_buildRom = p
	
def findBuildRom():
	if len(validBuildOptions()) == 1:
		return validBuildOptions()[0]
	return 'EUR_MQD'

def buildRom():
	global _buildRom
	
	if _buildRom is not None:
		return _buildRom
		
	if len(sys.argv) < 2:
		print('incorrect usage, pass rom name')
		exit(0)

	_buildRom = sys.argv[1]
	return _buildRom
	
def romPath(rom = ''):
	return fixSlashPath('roms/%s/%s' % (buildRom(), rom))
	
def getAssetPath():
	global _assetPath

	_assetPath = fixSlashPath('assets/%s' % buildRom())
	return _assetPath
	
def assetPath(s = ''):
	return fixSlashPath('%s/%s' % (getAssetPath(), s))
	
def zapdBinary():
	return str(Path('tools/ZAPD/ZAPD.out'))
	
def yaz0Binary():
	return str(Path('tools/yaz0'))
	
def createDir(path):
	Path.mkdir(Path(path), parents=True, exist_ok = True)
	
def mkdir(path):
	createDir(path)
	
def relPath(path, sub = None):
	if sub is None:
		sub = basedir
	left = os.path.abspath(sub)

	path = os.path.abspath(path)

	if left.startswith(path):
		raise IOError('path is not under this project:\n%s\n%s' % (left, path))
	r = path[len(left):]
	if r[0] == '/' or r[0] == '\\':
		return r[1:]
	return r

basedir = Path(__file__).absolute().parent.parent