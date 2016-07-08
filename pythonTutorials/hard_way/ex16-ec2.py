#a simple text editor

from sys import argv

script, filename = argv

print "We're going to erase %r." % filename
print "If you don't want that, hit CTRL-C (^C)."
print "If that's okay, git RETURN."

raw_input("?")

print "Opening the file..."
target = open(filename, 'w') #truncates file before opening

print "Truncating the file. Goodbye!"
#target.truncate()

print "Now I'm going to ask you for three lines."

line1 = raw_input("line 1: ")
line2 = raw_input("line 2: ")
line3 = raw_input("line 3: ")

print "I'm going to write these to a file."

#using strings and escapes
#composite_str = line1 + "\n" + line2 + "\n" + line3 + "\n"

#using formats
composite_str = "%s\n"*3 % (line1, line2, line3)

target.write(composite_str)

print "And finally, we close it."
target.close()
