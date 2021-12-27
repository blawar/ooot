
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
			#f.write(('0x%%%d.%dX, ' % (self.getElementSize() * 2, self.getElementSize() * 2)) % (n))
			
		f.write(', '.join(lst))
			
		f.write('};\n\n')
		
	def getSize(self):
		return int(self.sz / self.getElementSize())
		
	def getElementSize(self):
		return self.elementSize

sections = {'src/port/rsp.c': [
		Section('gSoundFontTable', 0xBCC270, 0x270, 1),
		Section('gSequenceFontTable', 0xBCC4E0, 0x1C0, 1),
		Section('gSequenceTable', 0xBCC6A0, 0x6F0, 1),
		Section('gSampleBankTable', 0xBCCD90, 0x80, 1),
		Section('rspAspMainDataStart', 0xBCCE10, 0x2E0),
		Section('D_80155F50', 0xBCD0F0, 0x1630, 1),
		Section('D_80157580', 0xBCE720, 0x420, 1),
		Section('D_801579A0', 0xBCEB40, 0x390, 1),
		Section('gJpegUCodeData', 0xBCEED0, 0x60),
		Section('D_801120C0', 0xB89260, 0xFB0, 8),
		Section('D_80113070', 0xB8A210, 0x18C0, 1),
		Section('gJpegUCode', 0xB8BAD0, 0xAF0, 8)
	],
	'src/port/rsp_boot.c': [
		Section('D_80009320', 0x9F20, 0xD0, 1),
		Section('D_800093F0', 0x9FF0, 0x20, 1)
	],
	'src/port/code_800F9280.c': [
		Section('sSeqCmdWrPos', 0xBAA5A0, 0x4, 1),
		Section('sSeqCmdRdPos', 0xBAA5A4, 0x4, 1),
		Section('D_80133408', 0xBAA5A8, 0x1, 1),
		Section('D_8013340C', 0xBAA5AC, 0x1, 1),
		Section('D_80133410', 0xBAA5B0, 0x4, 1),
		Section('gAudioSpecId', 0xBAA5B4, 0x1, 1),
		Section('D_80133418', 0xBAA5B8, 0x1, 1),
		'''
		Section('D_80133420', 0xBAA5C0, 0x48),
		Section('D_80133468', 0xBAA608, 0x48),
		Section('D_801334B0', 0xBAA650, 0x90),
		Section('D_80133540', 0xBAA6E0, 0x48),
		Section('D_80133588', 0xBAA728, 0x48),
		Section('D_801335D0', 0xBAA770, 0x48),
		Section('D_80133618', 0xBAA7B8, 0x48),
		Section('D_80133660', 0xBAA800, 0x48),
		Section('D_801336A8', 0xBAA848, 0x48),
		Section('D_801336F0', 0xBAA890, 0x48),
		Section('D_80133738', 0xBAA8D8, 0x90)
		'''
	]
}

with open('baserom.z64', 'rb') as z64:
	for filename, s in sections.items():
		with open(filename, 'w') as f:
			f.write('#include "global.h"\n\n')
			
			for section in s:
				section.serialize(f, z64)