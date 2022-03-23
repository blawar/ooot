import struct
import json
from oot import *

conf = config()

sampleBankTable = None

symbols = {}

class Root:
	def __init__(self):
		self.address = 0
		self.offset = 0
root = Root()

class Symbol:
	def __init__(self, name, definition, offset, static):
		self.name = name
		self.definition = definition
		self.offset = offset
		self.static = static
		
	def __str__(self):
		if self.static:
			return 'static ' + self.definition
		return self.definition

def registerSymbol(name, definition, offset, static = True):
	global symbols
	
	symbols[offset] = Symbol(name, definition, offset, static = static)
	
def getSymbolNameByOffset(offset, ptr = False, base = -1):
	if offset > 0:
		for name, s in symbols.items():
			if s.offset == offset + base:
				if ptr:
					return '&' + s.name
				return s.name
		return '0x%8.8X' % offset
	return '0x%8.8X' % offset

def reverse(s):
	return s[::-1]
	return int.from_bytes(s, byteorder='big').to_bytes(len(s), 'little')

def readConvert(f, size, swap = True):
	pos = f.tell()
	r = f.read(size)
	
	if len(r) != size:
		raise IOError('failed to read %d bytes, got %d' % (size, len(r)))

	return r

def readS8(f, swap = True, byteorder='big'):
	return int.from_bytes(readConvert(f, 1, swap), byteorder=byteorder, signed=True)
	
def readU8(f, swap = True, byteorder='big'):
	return int.from_bytes(readConvert(f, 1, swap), byteorder=byteorder, signed=False)
	
def readS16(f, swap = True, byteorder='big'):
	return int.from_bytes(readConvert(f, 2, swap), byteorder=byteorder, signed=True)
	
def readU32(f, swap = True, byteorder='big'):
	return int.from_bytes(readConvert(f, 4, swap), byteorder=byteorder, signed=False)
	
def readS32(f, swap = True, byteorder='big'):
	return int.from_bytes(readConvert(f, 4, swap), byteorder=byteorder, signed=True)
	
def readFloat(f, swap = True):
	b = readConvert(f, 4, swap)
	return float(struct.unpack('>f', b)[0])
	
	
class ConvFile:
	def __init__(self, path, mode):
		self.path = path
		self.i = open(path, 'rb')
		self.o = open(path + '_le', 'wb')
		if True:
			self.seek(0)
			buffer = self.i.read()
			self.o.write(buffer)
		else:
			self.seek(0)
			buffer = self.i.read()
			self.o.write(b'\xFF' * len(buffer))
		self.seek(0)
		
		self.writes = {}
		
	def __enter__(self):
		return self
		
	def __exit__(self, type, value, tb):
		self.close()
		
	def seek(self, offset):
		self.i.seek(offset)
		self.o.seek(offset)
		self.pos = offset
		
	def tell(self):
		return self.i.tell()
		
	def close(self):
		f = self.o
		self.i.close()
		self.o.close()
		
	def read(self, n, swap = True):
		if n == 0:
			raise IOError('null read')
		pos = self.i.tell()
		self.seek(pos)

		r = self.i.read(n)
		
		if len(r) != n:
			raise IOError('incomplete read: %d, expected %d' % (len(r), n))
		
		if swap:
			self.write2(reverse(r), n)
		else:
			self.write2(r, n)
		self.o.flush()
		return r
		
	def write2(self, data, n):		
		f = self.o
		f.seek(self.pos)
		f.write(data)
		#self.writes[self.pos] = data
		self.pos += len(data)
		
	#def write(self, data):
	#	self.o.write(data)
	#	self.i.seek(self.o.tell())
	#	return len(data)


class Section:
	def __init__(self, name, offset, sz, elementSize = 8):
		self.name = name
		self.offset = offset
		self.sz = sz
		self.elementSize = elementSize
		
	def serialize(self, f, z64):
		z64.seek(self.offset)

		if self.getSize() == self.getElementSize():
			f.write('u%d %s = ' % (self.getElementSize() * 8, self.name))
			buffer = z64.read(self.getElementSize())
			n = int.from_bytes(buffer, "big")
			f.write(('0x%%%d.%dX' % (self.getElementSize() * 2, self.getElementSize() * 2)) % (n))
			f.write(';\n\n')
			return

		f.write('u%d %s[0x%X] = {' % (self.getElementSize() * 8, self.name, self.getSize()))
		
		lst = []
		while z64.tell() < self.offset + self.sz:
			buffer = z64.read(self.getElementSize())
			n = int.from_bytes(buffer, "big")
			lst.append(('0x%%%d.%dX' % (self.getElementSize() * 2, self.getElementSize() * 2)) % (n))
			
		f.write(', '.join(lst))
			
		f.write('};\n\n')
		
	def getSize(self):
		return int(self.sz / self.getElementSize())
		
	def getElementSize(self):
		return self.elementSize
		
	def includes(self):
		return []
		
class Reloc:
	def __init__(self, address, size, medium, cachePolicy, shortData1, shortData2, shortData3, dataFile, f):
		self.address = address
		self.size = size
		self.medium = medium
		self.cachePolicy = cachePolicy
		self.shortData1 = shortData1
		self.shortData2 = shortData2
		self.shortData3 = shortData3
		
		self.dataFile = dataFile
		self.f = f
		
	def getSymbol(self):
		return '0x%8.8X' % (self.address)
		
	def render(self, f):
		pass
		
def OFFSET(o):
	if o > 0x2BDC0:
		raise IOError('bad offset: %8.8X' % o)
	return o
	
def ALIGN(n, a = 8):
	if n % a == a:
		return n
		
	return ((n // a) * a) + a

class AdpcmLoop:
	def __init__(self, f, parent):
		self.pos = f.tell()
		self.parent = parent
		self.start = readU32(f)
		self.end = readU32(f)
		self.count = readU32(f)
		self.unk_0C = f.read(4, swap = False)
		
		sunks = []
		for i in range(4):
			sunks.append("{0:#0{1}x}".format(self.unk_0C[i],4))
		
		self.states = []
		sstates = []
		if self.count > 0:
			for i in range(16):
				s = readS16(f, swap = False, byteorder='big')
				self.states.append(s)
				sstates.append("{0:#0{1}x}".format(s,6))
		registerSymbol(self.getSymbol(), 'AdpcmLoop %s = {.start = %d, .end = %d, .count = %d, .unk_0C = {%s}, .state = {%s}};' % (self.getSymbol(), self.start, self.end, self.count, ', '.join(sunks), ', '.join(sstates)), self.pos)
				
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'loop_%8.8X' % self.pos

class AdpcmBook:
	def __init__(self, f, parent):
		self.pos = f.tell()
		self.order = readS32(f)
		self.npredictors = readS32(f)
		print('.order = %d, .npred = %d, .offset = %8.8X' % (self.order, self.npredictors, f.tell()))

		allocLen = ALIGN(self.order * self.npredictors * 8, 8)
		sbooks = []
		self.books = [] # TODO LOOP THROUGH: size 8 * order * npredictors. 8-byte aligned
		for i in range(allocLen):
			b = readS16(f, swap = False, byteorder='big')
			self.books.append(b)
			#sbooks.append('0x%4.4X' % b)
			sbooks.append("{0:#0{1}x}".format(b,6))
			
		registerSymbol(self.getSymbol(), 'VAdpcmBook<%d> %s = {.order = %d, .npredictors = %d, .book = {%s}};' % (allocLen, self.getSymbol(), self.order, self.npredictors, ','.join(sbooks)), self.pos)
			
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'book_%8.8X' % self.pos

def RSHIFT(n, offset, length):
	return (n >> offset) & ((0x01 << length) - 1)

class BufferU8:
	def __init__(self, parent, offset, size, dataFile = 'baserom/Audiotable', prefix = 'buffer_'):
		self.pos = offset
		self.prefix = prefix

		data = []
		with open(romPath('baserom.z64') if dataFile == 'baserom' else assetPath(dataFile), 'rb') as f:
			f.seek(offset + sampleBankTable.getBankOffset(parent.shortData1 >> 8))
			for b in f.read(size):
				data.append(hex(b))

			if len(data) != size:
				raise IOError('did not read all of u8 buffer')
		registerSymbol(self.getSymbol(), 'u8 %s[] = {%s};' % (self.getSymbol(), ', '.join(data)), self.pos + 0x10000000)

	def getSymbol(self):
		return '%s%8.8X' % (self.prefix, self.pos)


class SoundFontSample:
	def __init__(self, f, parent):
		self.pos = f.tell()
		modes, u2, length, address, loopOffset, bookOffset = struct.unpack(">bbHLLL", f.read(4 * 4))
		f.seek(self.pos)
		self.flags = readU32(f)
		self.sampleOffset = readU32(f)
		self.loopOffset = readU32(f)
		self.bookOffset = readU32(f)
		
		pos = f.tell()
		

		#self.codec = RSHIFT(self.flags, 0, 4)
		#self.medium = RSHIFT(self.flags, 4, 2)
		#self.unk_bit26 = RSHIFT(self.flags, 6, 1)
		#self.unk_bit25 = RSHIFT(self.flags, 7, 1)
		#self.size = RSHIFT(self.flags, 8, 24)

		self.size = RSHIFT(self.flags, 0, 24)
		self.unk_bit25 = RSHIFT(self.flags, 24, 1)
		self.unk_bit26 = RSHIFT(self.flags, 25, 1)
		self.medium = RSHIFT(self.flags, 26, 2)
		self.codec = RSHIFT(self.flags, 28, 4)

		if self.size != length:
			raise IOError('bad size, got %d expected %d' % (length, self.size))

		if self.codec != ((modes >> 4) & 0xF):
			raise IOError('bad codec, got %d, expected %d' % ((modes >> 4) & 0xF, self.codec))

		if self.medium != ((modes & 0xC) >> 2):
			raise IOError('bad medium, got %d expected %d' % ((modes & 0xC) >> 2, self.medium))

		print('sample flags: %8.8X, size = %d, codec = %d, medium = %d, unk_bit26 = %d, unk_bit25 = %d, sampleOffset = %8.8X' % (self.flags, self.size, self.codec, self.medium, self.unk_bit26, self.unk_bit25, self.sampleOffset))
		
		#print('sample flags: %8.8X, size = %d' % (self.flags, RSHIFT(self.flags, 8, 24)))
		#exit(0)
		#if OFFSET(self.sampleOffset) > 0:
		#	pass
			#print('sample flags: %8.8X' % self.flags)
			#exit(0)
			#f.seek(self.sampleOffset + parent.address)

		
		if OFFSET(self.loopOffset) > 0:
			f.seek(self.loopOffset + parent.address)
			self.loop = AdpcmLoop(f, parent)
		
		if OFFSET(self.bookOffset) > 0:
			f.seek(self.bookOffset + parent.address)
			self.book = AdpcmBook(f, parent)

		sampleSymbol = '0x%8.8X' % self.sampleOffset

		if self.size > 0 and self.unk_bit25 != 1:
			if self.medium == 0 and 1 == 0:
				self.sampleBuffer = BufferU8(parent, offset = self.sampleOffset, size = self.size, dataFile = 'baserom/Audiotable')
				self.unk_bit25 = 1
				sampleSymbol = self.sampleBuffer.getSymbol()

		f.seek(pos)
		
		registerSymbol(self.getSymbol(), 'SoundFontSample %s = {.size = %d, .unk_bit25 = %d, .unk_bit26 = %d, .medium = %d, .codec = %d, .sampleAddr = (u8*)%s, .loop = %s, .book = (AdpcmBook*)%s};' % (self.getSymbol(), self.size, self.unk_bit25, self.unk_bit26, self.medium, self.codec, sampleSymbol, getSymbolNameByOffset(self.loopOffset, base = parent.address, ptr = True), getSymbolNameByOffset(self.bookOffset, base = parent.address, ptr = True)), self.pos)
		
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'sf_sample_%8.8X' % self.pos
		
class SoundFontSound:
	def __init__(self, f, parent, register = True):
		self.parent = parent
		self.pos = f.tell()
		self.sampleOffset = readU32(f)
		self.tuning = readFloat(f)
		
		pos = f.tell()
		
		if OFFSET(self.sampleOffset) > 0:
			f.seek(self.sampleOffset + parent.address)
			self.sample = SoundFontSample(f, parent)
			
		f.seek(pos)

		print('SoundFontSound: %8.8X, tuning: %f' % (self.sampleOffset, self.tuning))
		
		if register:
			registerSymbol(self.getSymbol(), 'SoundFontSound %s = %s;' % (self.getSymbol(), self.render()), self.pos)
		
	def render(self):
		return '{.sample = %s, .tuning = %f}' % (getSymbolNameByOffset(self.sampleOffset, base = self.parent.address, ptr = True), self.tuning)
		
	def getSymbol(self):
		return 'sf_sound_%8.8X' % self.pos

class Drum:
	def __init__(self, f, parent):
		self.pos = f.tell()
		self.releaseRate = readU8(f)
		self.pan = readU8(f)
		self.loaded = readU8(f)
		
		readU8(f) # padding
		
		self.soundFontSound = SoundFontSound(f, parent)
		
		self.envelopeOffset = readU32(f)
		
		pos = f.tell()

		envelopeSymbol = '0x00000000'
		if OFFSET(self.envelopeOffset) > 0:
			f.seek(self.envelopeOffset + parent.address)
			self.adsrEnvelope = AdsrEnvelope(f)
			envelopeSymbol = self.adsrEnvelope.getSymbol()
			
		f.seek(pos)
		
		print('Drum: releaseRate: %d, pan: %d, envelopeOffset: %8.8X' % (self.releaseRate, self.pan, self.envelopeOffset))
		registerSymbol(self.getSymbol(), 'Drum %s = {.releaseRate = %d, .pan = %d, .loaded = %d, .sound = %s, .envelope = %s};' % (self.getSymbol(), self.releaseRate, self.pan, self.loaded, self.soundFontSound.render(), envelopeSymbol), self.pos)
		
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'drum_%8.8X' % self.pos

class AdsrEnvelope:
	def __init__(self, f):
		self.pos = f.tell()

		self.delays = []
		self.args = []
		lst = []

		delay = 0

		for i in range(32):
			if delay < 0:
				break
			delay = readS16(f)
			arg = readS16(f)
			lst.append('AdsrEnvelope(%d, %d)' % (delay, arg))

		
		registerSymbol(self.getSymbol(), 'AdsrEnvelope %s[] = {%s};' % (self.getSymbol(), ', '.join(lst)), self.pos)
		
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'adsrEnvelope_%8.8X' % self.pos

class Instrument:
	def __init__(self, f, parent):
		self.pos = f.tell()
		self.loaded = readU8(f)
		self.normalRangeLo = readU8(f)
		self.normalRangeHi = readU8(f)
		self.releaseRate = readU8(f)
		
		self.envelopeOffset = readU32(f)
		self.lowNotesSound = SoundFontSound(f, parent, register = False)
		self.normalNotesSound = SoundFontSound(f, parent, register = False)
		self.highNotesSound = SoundFontSound(f, parent, register = False)
		
		pos = f.tell()

		if OFFSET(self.envelopeOffset) > 0:
			f.seek(self.envelopeOffset + parent.address)
			self.adsrEnvelope = AdsrEnvelope(f)
			
		f.seek(pos)
		
		#print('Instrument: normalRangeLo: %d, normalRangeHi: %d, releaseRate: %d, envelopeOffset = %8.8X (%8.8X), lowNotesSound = %s, normalNotesSound = %s, highNotesSound = %s' % (self.normalRangeLo, self.normalRangeHi, self.releaseRate, self.envelopeOffset, parent.address))
		registerSymbol(self.getSymbol(), 'Instrument %s = {.loaded = %d, .normalRangeLo = %d, .normalRangeHi = %d, .releaseRate = %d, .envelope = %s, .lowNotesSound = %s, .normalNotesSound = %s, .highNotesSound = %s};' % (self.getSymbol(), self.loaded, self.normalRangeLo, self.normalRangeHi, self.releaseRate, getSymbolNameByOffset(self.envelopeOffset, base = parent.address, ptr = False), self.lowNotesSound.render(), self.normalNotesSound.render(), self.highNotesSound.render()), self.pos)
		
	def render(self):
		return ''
		
	def getSymbol(self):
		return 'instrument_%8.8X' % self.pos

class JumpTable:
		def __init__(self, address, lst, parent, f, prefix = 'jmp_', datatype = 'void*'):
			self.address = address
			self.prefix = prefix
			self.parent = parent
			
			rlst = []
			
			for i in lst:
				if i is None or i == 0:
					rlst.append('0x00000000')
				else:
					rlst.append('&' + getSymbolNameByOffset(i, base = parent.address))
			
			registerSymbol(self.getSymbol(), '%s %s[] = {%s};' % (datatype, self.getSymbol(), ', '.join(rlst)), offset = address)
			
		def getSymbol(self):
			return '%s%8.8X' % (self.prefix, self.address + self.parent.address)
			
class Array:
		def __init__(self, address, lst, parent, f, prefix = 'array_', datatype = 'u8'):
			self.address = address
			self.prefix = prefix
			
			rlst = []
			
			for i in lst:
				rlst.append(i.render())
			
			registerSymbol(self.getSymbol(), 'struct %s %s[%d] = {%s};' % (datatype, self.getSymbol(), len(lst), ', '.join(rlst)), offset = address)
			
		def getSymbol(self):
			return '%s%8.8X' % (self.prefix, self.address)

class FontReloc(Reloc):
	def __init__(self, address, size, medium, cachePolicy, shortData1, shortData2, shortData3, dataFile, f):
		super(FontReloc, self).__init__(address, size, medium, cachePolicy, shortData1, shortData2, shortData3, dataFile, f)
		self.pos = address
		self.sampleBankId1 = (shortData1 >> 8) & 0xFF
		self.sampleBankId2 = (shortData1) & 0xFF
		self.numInstruments = (shortData2 >> 8) & 0xFF
		self.numDrums = shortData2 & 0xFF
		self.numSfx = shortData3
		
		f.seek(address)
		self.offsets = []
		self.offsets.append(readU32(f)) # drums
		self.offsets.append(readU32(f)) # SoundFontSound
		
		for i in range(2, self.numInstruments + 2): # instruments
			self.offsets.append(readU32(f))
		
		print('bankId1 = %d, bankId2 = %d, numInstruments = %d, numDrums = %d, , numSfx = %d' % (self.sampleBankId1, self.sampleBankId2, self.numInstruments, self.numDrums, self.numSfx))
		
		
		drums = []
		sfxs = []
		instruments = []
		
		f = self.f
		
		symbols = []

		if self.offsets[0] > 0:
			lst = []
			
			for i in range(self.numDrums):
				f.seek(self.offsets[0] + self.address + (i * 4))
				p = readS32(f)
				
				if p > 0:
					f.seek(p + self.address)
					lst.append(p + self.address)
					d = Drum(f, self)
					drums.append(d)
				else:
					lst.append(None)
			if 0x00000740 == self.offsets[0]:
				x = 1
			tbl = JumpTable(address = self.offsets[0] + self.address, lst = lst, parent = root, f = f, prefix = 'drum_jmp_', datatype = 'Drum*')
			
		if self.offsets[1] > 0:
			lst = []
			f.seek(self.offsets[1] + self.address)
			for i in range(self.numSfx):
				sf = SoundFontSound(f, self, register = False)
				sfxs.append(sf)
				
			tbl = Array(address = self.offsets[1] + self.address, lst = sfxs, parent = self, f = f, prefix = 'sfxs_', datatype = 'SoundFontSound')
				
		for i in range(2, self.numInstruments + 2):
			if self.offsets[i] > 0:
				f.seek(self.offsets[i] + self.address)
				inst = Instrument(f, self)
				instruments.append(inst)
				
		symlist = []
		for offset in self.offsets:
			symlist.append(getSymbolNameByOffset(offset, base = self.address))
		#registerSymbol(self.getSymbol(), 'void* %s[] = {%s};' % (self.getSymbol(), ', '.join(symlist)), self.pos)
		self.tbl = JumpTable(address = address, lst = self.offsets, parent = self, f = f)
	
	def getSymbol(self):
		return self.tbl.getSymbol()

	def render(self, f):
		if self.offsets[0] > 0:
			instList = '0x%8.8X' % self.offsets[0]
		else:
			instList = 'nullptr'
		#f.write('SoundFont %s = { .numInstruments = %d, .numDrums = %d, .sampleBankId1 = %d, .sampleBankId2 = %d, .numSfx = %d, .instruments = %s};\n' % (self.getSymbol(), self.numInstruments, self.numDrums, self.sampleBankId1, self.sampleBankId2, self.numSfx, instList, drumList))

	def getName(self):
		return 'font_%X' % self.address		

		
class Table(Section):
	def __init__(self, name, offset, sz, dataFile):
		super(Table, self).__init__(name, offset, sz, 1)
		
		self.dataFile = dataFile
		self.relocs = []

	def getRealId(self, id):
		if self.relocs[id].size == 0:
			return self.relocs[id].address
		return id

	def getBankOffset(self, id):
		id = self.getRealId(id)

		return self.relocs[id].address

	def load(self, z64):
		relocs = []
		z64.seek(self.offset)

		numEntries = readS16(z64, swap = False)
		unkMediumParam = readS16(z64, swap = False)
		address = readU32(z64, swap = False)
		
		z64.read(8) # padding

		with ConvFile(assetPath(self.dataFile), 'rb') as x:
			while z64.tell() < self.offset + self.sz:
				address = readU32(z64, swap = False)
				size = readU32(z64, swap = False)
				medium = readS8(z64, swap = False)
				cachePolicy = readS8(z64, swap = False)
				shortData1 = readS16(z64, swap = False)
				shortData2 = readS16(z64, swap = False)
				shortData3 = readS16(z64, swap = False)

				reloc = self.getReloc(address, size, medium, cachePolicy, shortData1, shortData2, shortData3, f = x)
				relocs.append(reloc)
		self.relocs = relocs

		
	def serialize(self, f, z64):
		global symbols
		z64.seek(self.offset)
		
		numEntries = readS16(z64, swap = False)
		unkMediumParam = readS16(z64, swap = False)
		address = readU32(z64, swap = False)
		
		z64.read(8) # padding


		lst = []
		relocs = []
		
		with ConvFile(assetPath(self.dataFile), 'rb') as x:
			while z64.tell() < self.offset + self.sz:
				address = readU32(z64, swap = False)
				size = readU32(z64, swap = False)
				medium = readS8(z64, swap = False)
				cachePolicy = readS8(z64, swap = False)
				shortData1 = readS16(z64, swap = False)
				shortData2 = readS16(z64, swap = False)
				shortData3 = readS16(z64, swap = False)

				reloc = self.getReloc(address, size, medium, cachePolicy, shortData1, shortData2, shortData3, f = x)
				relocs.append(reloc)
				lst.append('{ .romAddr = (uintptr_t)%s, .size = 0x%8.8X, .medium = 0x%2.2X, .cachePolicy = %d, .shortData1 = 0x%4.4X, .shortData2 = 0x%4.4X, .shortData3 = 0x%4.4X }' % (reloc.getSymbol(), size, medium, cachePolicy, shortData1, shortData2, shortData3))
				#reloc.render(f)
		self.relocs = relocs
			
		definition = ('AudioTableDef %s = {\n.numEntries = 0x%4.4X, .unkMediumParam = 0x%4.4X, .romAddr = 0x%8.8X, .pad = {0}, .entries = {\n' % (self.name, numEntries, unkMediumParam, address))

		definition += (',\n'.join(lst))
			
		definition += ('\n}};')
		
		registerSymbol(self.name, definition, self.offset, static = False)
		
		for offset, definition in symbols.items():
			f.write('%s\n\n' % (definition))
			
		symbols = {}
		
	def getReloc(self, address, size, medium, cachePolicy, shortData1, shortData2, shortData3, f):
		return Reloc(address, size, medium, cachePolicy, shortData1, shortData2, shortData3, self.dataFile, f = f)
		
		
	def includes(self):
		return ['z64audio.h']
		
class FontTable(Table):
	def __init__(self, name, offset, sz, dataFile):
		super(FontTable, self).__init__(name, offset, sz, dataFile)
		
	def getReloc(self, address, size, medium, cachePolicy, shortData1, shortData2, shortData3, f):
		return FontReloc(address, size, medium, cachePolicy, shortData1, shortData2, shortData3, self.dataFile, f = f)

sections = {'misc/rsp.h': [
		FontTable('gSoundFontTable', conf.sections.gSoundFontTable.offset, conf.sections.gSoundFontTable.size, 'baserom/Audiobank'),
		Section('gSequenceFontTable', conf.sections.gSequenceFontTable.offset, conf.sections.gSequenceFontTable.size, 2),
		Table('gSequenceTable', conf.sections.gSequenceTable.offset, conf.sections.gSequenceTable.size, 'baserom/Audioseq'),
		Table('gSampleBankTable', conf.sections.gSampleBankTable.offset, conf.sections.gSampleBankTable.size, 'baserom/Audiotable'),
		Section('rspAspMainDataStart', conf.sections.rspAspMainData.offset, conf.sections.rspAspMainData.size, 4),
		Section('D_80155F50', conf.sections.rspF3DZEXText.offset, conf.sections.rspF3DZEXText.size, 1),
		Section('D_80157580', conf.sections.rspF3DZEXData.offset, conf.sections.rspF3DZEXData.size, 1),
		Section('D_801579A0', conf.sections.rspS2DEXData.offset, conf.sections.rspS2DEXData.size, 1),
		Section('gJpegUCodeData', conf.sections.rspJpegData.offset, conf.sections.rspJpegData.size),
		Section('D_801120C0', conf.sections.rspAspMainText.offset, conf.sections.rspAspMainText.size, 8),
		Section('D_80113070', conf.sections.rspS2DEXText.offset, conf.sections.rspS2DEXText.size, 1),
		Section('gJpegUCode', conf.sections.rspJpegTextStart.offset, conf.sections.rspJpegTextStart.size, 8)
	],
	'misc/rsp_boot.h': [
		Section('D_80009320', conf.sections.rspBootText.offset, conf.sections.rspBootText.size, 1),
		Section('D_800093F0', conf.sections.D_800093F0.offset, conf.sections.D_800093F0.size, 1)
	],
	'misc/code_800F9280.h': [
		Section('sSeqCmdWrPos', conf.sections.sSeqCmdWrPos.offset, conf.sections.sSeqCmdWrPos.size, 1),
		Section('sSeqCmdRdPos', conf.sections.sSeqCmdRdPos.offset, conf.sections.sSeqCmdRdPos.size, 1),
		Section('D_80133408', conf.sections.D_80133408.offset, conf.sections.D_80133408.size, 1),
		Section('D_8013340C', conf.sections.D_8013340C.offset, conf.sections.D_8013340C.size, 1),
		Section('D_80133410', conf.sections.D_80133410.offset, conf.sections.D_80133410.size, 1),
		Section('gAudioSpecId', conf.sections.gAudioSpecId.offset, conf.sections.gAudioSpecId.size, 1),
		Section('D_80133418', conf.sections.D_80133418.offset, conf.sections.D_80133418.size, 1),
	]
}

createDir(assetPath('misc'))

with open(romPath('baserom.z64'), 'rb') as z64:
	sampleBankTable = Table('gSampleBankTable', conf.sections.gSampleBankTable.offset, conf.sections.gSampleBankTable.size, 'baserom/Audiotable')
	sampleBankTable.load(z64)

	for filename, s in sections.items():
		with open(assetPath(filename), 'w') as f:
			f.write('#include "global.h"\n')
			includes = {}
			for section in s:
				for i in section.includes():
					includes[i] = i
					
			for i in includes.keys():
				f.write('#include "%s"\n' % i)
				
			f.write('\n')

			for section in s:
				section.serialize(f, z64)