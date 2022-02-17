import sys
import os
import os.path
from pathlib import Path

_assetPath = None
_buildRom = None

def fixSlashPath(path):
	#return path.replace('\\', '/')
	return path.replace('/', '\\')
	
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
	return 'tools/ZAPD/ZAPD.out'
	
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
	
basedir = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__.replace('\\', '/'))), '../'))
