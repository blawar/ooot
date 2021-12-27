import sys
import re

magic = '/* fixed */'

print(sys.argv[1])

with open(sys.argv[1], 'r') as f:
	buffer = f.read()

if buffer.startswith(magic):
	print('already fixed')
	exit(0)

buffer = buffer.replace(' ', '').replace('\r', '\n')

buffer = re.sub(r'//[^\n]*\s', '', buffer, flags=re.DOTALL).strip()
l = []
for x in buffer.split(','):
	if not x:
		continue
	x = x[2:]
	l.append('0x' + x[0:2])
	l.append('0x' + x[2:4])
	l.append('0x' + x[4:6])
	l.append('0x' + x[6:8])
	l.append('0x' + x[8:10])
	l.append('0x' + x[10:12])
	l.append('0x' + x[12:14])
	l.append('0x' + x[14:16])

	'''
	num = int(x, 16)
	num = num.to_bytes(8, byteorder='big')
	num = int.from_bytes(num, byteorder='little')
	l.append('0x%16.16X' % num)
	'''
print(magic + ','.join(l))

with open(sys.argv[1], 'w') as f:
	f.write(magic + ','.join(l))