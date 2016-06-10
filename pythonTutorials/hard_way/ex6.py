#format string replacement using a string variable
x = "There are %d types of people." % 10
binary = "binary"
do_not = "don't"
#multiple format replacement
y = "Those who know %s and those who %s." % (binary, do_not)

print x
print y

#raw data format, replaces as 'string'
#best for formatting
print "I said: %r" % x
#string formatted, we need to include the ''
print "I also said: '%s'." % y

hilarious = False
joke_evaluation = "Isn't that joke so funny?! %r"

#dynamic format replacement
print joke_evaluation % hilarious

w = "This is the left side of..."
e = "a string with a right side."

#string concatenation
print w + e
