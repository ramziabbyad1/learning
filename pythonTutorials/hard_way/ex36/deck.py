from random import *

suits = [ u"\u2660", u"\u2665", u"\u2663", u"\u2666" ]
values = ['A'] + range(2, 11) + ['J', 'Q', 'K']

print repr(suits).decode()
print "suits raw: %s" % suits
print "values: ", values
