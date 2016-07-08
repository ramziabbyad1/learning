from sys import exit
from math import floor, sqrt

gold = 0

def square_room():
	global gold
	print "The room is the square_room"
	print "How much gold do you take?"

	print "You can choose any number."
	choice = raw_input("> ")
	how_much = int(choice)
	sq_len = sqrt(how_much)
	if floor(sq_len) == sq_len:
		print "Nice job, you chose a square."
		print "You get %dx%d cm's of gold sheeting." % (sq_len, sq_len)
		gold += sq_len
		start()
	elif how_much < 0:
		die("Wtf, areas can't be negative")
	else:
		square_room()
		

def gold_room():
	global gold
	print "This room is the gold_room"
	print "How much gold do you take?"
	
	print "You're choices are: any number containing 0, or 1"
	choice = raw_input("> ")
	
	if "0" in choice or "1" in choice:
		how_much = int(choice)
	else:
		dead("Man, learn to type a number...")

	if how_much < 50:
		print "Nice, you're not greedy, you win!"
		print "Try some of the other choices now.."
		gold += how_much
		start()
	else:
		dead("You greedy bastard!")

def bear_room():
	print "There is a bear here."
	print "The bear has lots of honey."
	print "The fat bear is in front of another door."
	print "How are you going to move the bear?"
	bear_moved = False

	while True:
		print "You're choices are 'take honey', 'taunt bear', 'open door'"
		choice = raw_input("> ")
			
		if choice == "take honey":
			dead("The bear looks at you then slaps your face off.")
		elif choice == "taunt bear" and not bear_moved:
			print "The bear has moved from the door. You can go through it now"
			bear_moved = True
		elif choice == "taunt bear" and bear_moved:
			dead("The bear gets pissed off and chews your leg off.")
		elif choice == "open door" and bear_moved:
			gold_room()
		else:
			print "I got no idea what that means."

def cthulhu_room():
	print "Here you see the great evil Cthulhu."
	print "He, it, whatever, stares at you and you go insane"
	print "Do you flee for your life or eat your head?"

	print "You're choices are 'flee', 'head'"
	choice = raw_input("> ")

	if "flee" in choice:
		start()
	elif "head" in choice:
		dead("Well that was tasty!")
	else:
		cthulhu_room() #recurse

def dead(why):
	print "You died with %d gold" % gold
	print why, "Good job!"
	exit(0)

def start():
	print "You are in a dark room."
	print "There is a door to your right and left and a ladder."
	print "Which do you take?"

	print "You're choice are: 'left', 'right', 'ladder', or 'suicide' to quit"
	choice = raw_input("> ")

	if choice == "left":
		bear_room()
	elif choice == "right":
		cthulhu_room()
	elif choice == "ladder":
		square_room()
	elif choice == "suicide":
		print "Is it really that bad?"
		print "Your choices are 'yes', 'no'"

		choice = raw_input("> ")
		if choice == "yes":
			dead("Another faded star..")
		else:
			start()
	else:
		dead("You stumble around the room for all eternity.")

start() #entry point
	
