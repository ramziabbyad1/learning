from sys import argv
i = 0
print "argv[1][1] = %c\n" % argv[1][1]
while i < len(argv):
	print "arg %d: %s\n" % (i, argv[i])
	i += 1

states = ["California", "Oregon", "Washington", "Texas"]

num_states = 4;
i = 0
while i < num_states:
	print "state %d: %s\n" % (i, states[i])
	i+= 1
