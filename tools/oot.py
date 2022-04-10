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
			
		try:
			self.hash_md5 = j['hash_md5']
		except:
			pass
		
		try:
			self.FILE_NAMES = j['FILE_NAMES']
		except:
			pass

class ConfSections:
	def __init__(self):
		pass

class Conf:
	def __init__(self, path):
		self.name = list(Path(path).parts)[-2]
		self.path = path
		self.parent = Path(path).parent
		self.sections = ConfSections()
		j = loadJson(path)

		try:
			for k,v in j['sections'].items():
				self.sections.__dict__[k] = ConfSection(v)
		except:
			pass
		self.rom = ConfRom(j['rom'])
		
		try:
			self.hashes = j['sha256']
		except:
			self.hashes = {}
			
	def romFile(self):
		search = ['baserom_original.z64', 'baserom_original.n64', 'baserom_original.v64']
		for i in search:
			if os.path.exists(self.parent.joinpath(i)):
				return self.parent.joinpath(i)
				
		return None
		
		
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
	priority = ['PAL_1.0', 'EUR_MQD']
	found = {}
	for conf in getAllConfs():
		if conf.romFile() is not None and os.path.exists(conf.parent.joinpath('zapd/Config.xml')):
			found[conf.name] = conf.name
			
	for rom in priority:
		if rom in found:
			return rom
			
	for rom in priority:
		return rom

	raise IOError('FATAL: Could not find any valid Ocarina of Time roms!')
	return None

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
	
configs = None

def getAllConfs():
	global configs
	if configs is not None:
		return configs
		
	configs = []
	for rom in validBuildOptions():
		configs.append(Conf(romPath('config.json', rom)))
		
	return configs

def findRomByHash(hashes):
	for conf in getAllConfs():
		try:
			for i in conf.hashes:
				if hashes['complete'] == i['complete'] or hashes['body'] == i['body']:
					return conf.name
		except:
			raise
	return None
	
def findRoms(z64 = True, n64 = True, v64 = True):
	roms = []
	searchPath = '.'
	if z64:
		for path in Path(searchPath).rglob('*.z64'):
			if 'verified' not in str(path):
				roms.append(path)
			
	if v64:
		for path in Path(searchPath).rglob('*.v64'):
			if 'verified' not in str(path):
				roms.append(path)
			
	if n64:
		for path in Path(searchPath).rglob('*.n64'):
			if 'verified' not in str(path):
				roms.append(path)
	
	return roms
		
def organizeRoms():
	print('searching for roms...')
	for path in findRoms():
		hashes = getRomHashes(path)
		
		r = findRomByHash(hashes)
		
		if r:
			newPath = romPath('baserom_original' + Path(path).suffix, r)
			
			if Path(path).resolve() != Path(newPath).resolve():
				try:
					os.rename(path, newPath)
				except:
					pass
				print('%s -> %s' % (path, newPath))
				
	print('done')

		

basedir = Path(__file__).absolute().parent.parent