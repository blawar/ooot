import sys
import os
import os.path
import json
import math
import hashlib
from pathlib import Path

_assetPath = None
_buildRom = None
_conf = None

def loadJson(path):
	try:
		with open(path, 'r') as f:
			return json.load(f)
	except:
		raise
		
def saveJson(path, data):
	try:
		with open(path, 'w') as f:
			json.dump(data, f, indent=4, sort_keys=True)
	except:
		raise

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
		j = loadJson(path)

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
	
def romPath(rom = '', root = None):
	if not root:
		root = buildRom()
	return fixSlashPath('roms/%s/%s' % (root, rom))
	
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
	
def sha256_buffer(buffer):
	m = hashlib.sha256()
	m.update(buffer)
	return m.hexdigest()

def getRomHashes(path):
	chunkSize = 0x100000 # 1MB
	headerSize = 0x1000

	r = {}
	with open(path, 'rb') as f:
		buffer = f.read()
	r['complete'] = sha256_buffer(buffer)
	r['body'] = sha256_buffer(buffer[headerSize:])
	r['chunks'] = []
	
	for i in range(int(math.ceil((len(buffer) - headerSize) / chunkSize))):
		offset = headerSize + (i * chunkSize)
		r['chunks'].append(sha256_buffer(buffer[offset:offset + chunkSize]))

	return r
	
def calcRomHashes():
	for rom in validBuildOptions():
		verified = romPath('verified', rom)
		configPath = romPath('config.json', rom)
		
		config = loadJson(configPath)
		config['sha256'] = []
		
		if not os.path.isdir(verified):
			continue
			
		for path in Path(verified).rglob('*.z64'):
			config['sha256'].append(getRomHashes(path))
			
		saveJson(configPath, config)
		

basedir = Path(__file__).absolute().parent.parent