from sys import argv

#argv use with more inputs
script, num1, num2, num3, num4 = argv
print "Running %s..." % script
n1 = float(num1)
n2 = float(num2)
n3 = float(num3)
n4 = float(num4)

s = raw_input("Enter '+' or '*': ")

#this form accepts other arith. operators
str_to_eval = "%s "*7 % (n1, s, n2, s, n3, s, n4)
print "%s = %s" % (str_to_eval, eval(str_to_eval))

print (str_to_eval + "="),
if s == '+':
	print n1 + n2 + n3 + n4
else:
	print n1 * n2 * n3 * n4
