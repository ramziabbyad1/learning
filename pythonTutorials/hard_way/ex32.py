#for loops

the_count = [1, 2, 3, 4, 5]
fruits = ['apples', 'oranges', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

for number in the_count:
	print "This is count %d" % number

for fruit in fruits:
	print "A fruit of type: %s" % fruit

for i in change:
	print "I got %r" % i

elements = []

#for i in range(0, 6):
for i in range(6): #default start = 0
	print "Adding %d to elements" % i
	elements.append(i)

for i in elements:
	print "Element was: %d" % i

elements2 = range(6)

i = 0
for e in elements2:
	print "elements2[%d] = %d" %(i, e) 
	i += 1

elements2.insert(3, 1)
print "elements2.count(1) = %d" % elements2.count(1) 
#some other useful list functions:
#insert(i, e), pop(i), count(e), extend, index, remove, reverse, sort 
