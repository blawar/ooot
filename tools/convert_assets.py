#!/usr/bin/python3

import os.path
from pathlib import Path
import os
import queue
import threading
import tqdm
from multiprocessing import cpu_count

basedir = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__.replace('\\', '/'))), '../'))


thread_count = 1 # cpu_count()

def info(m):
	tqdm.tqdm.write(m)

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
	rel = cleanPath(str(path)[len(searchdir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('assets/', rel)))
	ensureDirectory(out)
	cmd = '%s e -i %s -b baserom\ -o %s -osf %s -gsf 1 -rconf tools\ZAPDConfigs\MqDbg\Config.xml' % (zapd, getRelativePath(str(path)), out, out)
	info(cmd)
	os.system(cmd)
'''

threads = []
q = queue.LifoQueue()
searchdir = os.path.abspath('assets')

class Item:
	def __init__(self, path, rel, out):
		self.path = path
		self.rel = rel
		self.out = out
		
	def isStale(self):
		return os.path.exists(self.out)

def pngWorker(q, status):
	while not q.empty():
		try:
			item = q.get(block=False)
			
			if item is None:
				return

			path = item.path
			rel = item.rel
			out = item.out
			#rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
			#out = getRelativePath(os.path.abspath(os.path.join('build', rel)))

			type = rel.split('.')[-1]
			ensureDirectory(out)
			cmd = '%s btex -tt %s -i %s.png -o %s' % (zapd, type, rel, out)
			info(cmd)
			os.system(cmd)
			status.update(1)
		except queue.Empty as e:
			return
		except BaseException as e:
			info('PNG WORKER EXCEPTION: ' + str(e))
			#traceback.print_exc(file=sys.stdout)
		q.task_done()

for path in Path(searchdir).rglob('*.png'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel))) + '.inc.c'
	
	item = Item(path, rel, out)
	if not item.isStale():
		q.put(item)


with tqdm.tqdm(total=q.qsize()) as status:
	if thread_count == 1:
		pngWorker(q, status)
	else:
		for i in range(thread_count):
			t = threading.Thread(target=pngWorker, args=[q, status])
			t.daemon = True
			t.start()
			threads.append(t)
			
		info('q.join start')
		q.join()
		info('q.join end')
		for i in range(thread_count):
			q.put(None)
			
		info('waiting for threads to finish')
			
		i = 0
		for t in threads:
			t.join()
			i = i + 1
			info('joined thread %d' % i)

	
'''
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	type = rel.split('.')[-1]
	ensureDirectory(out)
	cmd = '%s btex -tt %s -i %s.png -o %s.inc.c' % (zapd, type, rel, out)
	info(cmd)
	os.system(cmd)
'''
	
searchdir = os.path.abspath('assets')
for path in Path(searchdir).rglob('*.jpg'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	ensureDirectory(out)
	cmd = '%s bren -i %s.jpg -o %s.jpg.inc.c' % (zapd, rel, out)
	info(cmd)
	os.system(cmd)
	
searchdir = os.path.abspath('assets')
for path in Path(searchdir).rglob('*.bin'):
	rel = cleanPath(str(path)[len(basedir):-4].strip('/').strip('\\'))
	out = getRelativePath(os.path.abspath(os.path.join('build', rel)))
	ensureDirectory(out)
	cmd = '%s bblb -i %s.bin -o %s.bin.inc.c' % (zapd, rel, out)
	info(cmd)
	os.system(cmd)
