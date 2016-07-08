"""
 A module full of functions
 can be imported using either of:
 import ex25 => called as ex25.foo()
 from ex25 import * => called as foo()
"""
def break_words(stuff):
	"""This function breaks a string into a list of words :) """
	return stuff.split(' ')

def sort_words(words):
	"""this function sorts a list of words """
	return sorted(words)

def print_first_word(words):
	"""prints and pops """
	print words.pop(0)

def print_last_word(words):
	"""prints and pops """
	print words.pop(-1)

def sort_sentence(sentence):
	"""sort a sentence as a list of words """
	return sort_words(break_words(sentence))

def print_first_and_last(sentence):
	words = break_words(sentence)
	print_first_word(words)
	print_last_word(words)

def print_first_and_last_sorted(sentence):
	words = sort_sentence(sentence)
	print_first_word(words)
	print_last_word(words)
