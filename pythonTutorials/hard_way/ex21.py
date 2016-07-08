def add(a, b):
	print "ADDING: %d + %d" % (a,b)
	return a + b
def subtract(a, b):
	print "SUBTRACTING: %d - %d" % (a, b)
	return a - b
def multiply(a, b):
	print "MULTIPLYING: %d * %d" % (a, b)
	return a * b
def divide(a, b):
	print "DIVIDING: %d / %d" % (a, b)
	return a / b
def formula(age, height, weight, iq):
	return add(age, subtract(height, multiply(weight, divide(iq, 2))))
def formula_literal(age, height, weight, iq):
	return age + (height - weight*iq/2)

print "Some math with fns"

age = add(30, 5)
height = subtract(78, 4)
weight = multiply(90, 2)
iq = divide(100, 2)

print "Age: %d, Height: %d, Weight: %d, IQ: %d" % (age, height, weight, iq)

print "Here is a puzzle"

what = add(age, subtract(height, multiply(weight, divide(iq, 2))))
print "what == formula ? %r" % (what == formula(age, height, weight, iq))
print "what == formula_literal ? %r" % what == formula_literal(age, height, weight, iq)
print "That becomes: ", what, "Can you do it by hand?" #35 + (74 - 180*25) = 35 + 74 - 4500 = -4391

