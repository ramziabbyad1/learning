#comma is used to add input before end of line
print "How old are you?",
age = raw_input()
print "How tall are you?",
height = raw_input()
print "How much do you weight?",
weight = raw_input()

#if an apostrophe is encounted, it is escaped
print "So, you're %r old, %r tall, %r fat." % (
	age, height, weight)

#no escape
print "So, you're %s old, %s tall, %s fat." % (
	age, height, weight)

#another way to use raw_input
age = raw_input('How old are you? ')
height = raw_input('How tall are you? ')
weight = raw_input('How fat are you? ')

print "So, you're %r old, %r tall, %r fat." % (
	age, height, weight)

#some practice questions
root = raw_input("Enter int to be squared: ")
square = int(root)**2
print "The %s^2 = %d" % (root, square)

