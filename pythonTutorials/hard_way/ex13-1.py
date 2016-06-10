#argv use with fewer vars
from sys import argv

script, size = argv

print "Running %r" % script
print "Printing %s lines.." % size

print "line\n"*int(size)
