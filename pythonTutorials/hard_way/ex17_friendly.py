from sys import argv
from os.path import exists

script, from_file, to_file = argv


in_file = open(from_file)
indata = in_file.read()

exists = exists(to_file)

out_file = open(to_file, 'w')
out_file.write(indata)

if exists : 
	print "Copyied %d bytes from %s to existing file %s" % (len(indata), from_file, to_file)
else: 
	print "Copyied %d bytes from %s to new file %s" % (len(indata), from_file, to_file)

out_file.close()
in_file.close()

