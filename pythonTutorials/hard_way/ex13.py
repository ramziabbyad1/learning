#input is passed before script execution
from sys import argv

#assign vars from input argv array (unpack argv)
script, first, second, third = argv

print "The script is called:", script
print "Your first variable is:", first
print "Your second variable is:", second
print "Your third variable is:", third
