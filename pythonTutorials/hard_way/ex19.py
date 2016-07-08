#function introduction
def cheese_and_crackers(cheese_count, boxes_of_crackers):
	print "You have %d cheeses!" % cheese_count
	print "You have %d boxes of crackers!" % boxes_of_crackers
	print "Man that's enough for a party!"
	print "Get a blacket.\n"

def my_fn(apples, oranges):
	print "You are comparing %r to %r" %(apples, oranges)
	if apples == oranges:
		print "apples == oranges"
	else:
		print "apples != oranges"

print "we can just give the function numbers directly.."
cheese_and_crackers(20, 30);

print "OR we can use variables from out script"
amount_of_cheese = 10
amount_of_crackers = 50

cheese_and_crackers(amount_of_cheese, amount_of_crackers)

print "We can even do math inside too:"
cheese_and_crackers(10+20, 5+6)

print "We can comine the two, variables and math"
cheese_and_crackers(amount_of_cheese + 100, amount_of_crackers + 1000)

my_fn(10, 20)	
my_fn('apples', 'oranges')
my_fn('apples', 'apples')
apples = 'apples'
oranges = 'oranges'
my_fn(apples, oranges)
my_fn(apples+oranges, apples+oranges)
