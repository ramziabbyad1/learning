#a simple text editor

from sys import argv

script, filename = argv

print "I'm going to open %r now. \n" % filename

txt = open(filename)

print "Here are the contents:\n\n%s" % txt.read()

txt.close()
