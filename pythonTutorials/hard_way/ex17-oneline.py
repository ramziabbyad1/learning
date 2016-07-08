
from sys import argv
from os.path import exists

script, from_file, to_file = argv



exists = exists(to_file)

open(to_file, 'w').write(open(from_file).read())

"""if exists : 
	print "Copyied %d bytes from %s to existing file %s" % (len(indata), from_file, to_file)
else: 
	print "Copyied %d bytes from %s to new file %s" % (len(indata), from_file, to_file)"""

#out_file.close()
#in_file.close()

