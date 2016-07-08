#0 based indices and range conventions are discussed
#by Dijkstra
def do_loop(end, inc):
	#while-loops
	
	numbers = []
	if inc == 0:
		print "inc should be > 0"
		return	
	i_s = range(0, end, inc)
	for i in i_s:
		print "At the top i is %d" % i
		numbers.append(i)
	
		#i += inc #this line does nothing
		print "Numbers now: ", numbers
		print "At the bottom i is %d" % i
	
	print "The numbers: "
	
	for num in numbers:
		print num

for i in range(4):
	print "even nums...\n\n"
	print "do_loop(%d, %d)" % (i, i % 2)
	do_loop(i, i % 2)
