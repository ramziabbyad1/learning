tabby_cat = "\tI'm tabbed in."
persian_cat = "I'm split\non a line."
backslash_cat = "I'm \\ a \\ cat."

fat_cat = """
I'll do a list.
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
"""

print tabby_cat
print persian_cat
print backslash_cat
print fat_cat

#infinite loop pending graphic

#while True:
#	for i in ["/","-","|","\\","|"]:
#		print "%s\r" % i,

#the escape sequences
#\\ #bashslash
#\' #single-quote
#\" #double-quote
#\a #asci bell (BEL)
#\b #asci backspace (BS)
#\f #ascii formfeed (FF)
#\n #ascii linefeed (LF)
#\N{name} #char named name in unicode db
#\r	#carriage-return (CR)
#\t #horizontal tab
#\uxxxx #char with 16-bit hex val (Unicode only)
#\Uxxxxxxxx #char with 32 bit hex (Unicode)
#\v #ascii vertical tab (VT)
#\ooo #char with octal val ooo
#\xhh #char with hex val hh


back_slash = "\\"
#if unicode name is wrong, print preprocessor error
#note this is done before interp., so can't make it dynamic
accented_o = u"\N{LATIN SMALL LETTER O WITH ACUTE}"
upside_dwn_ques = u"INVERTED QUESTION MARK"
begin_ques = u"\N{INVERTED QUESTION MARK}"
print "Went to the store for milk%ssugar\n" % back_slash
print 'But instead a man yelled \'Stop that!\''
print "I said \"fine!\""
#should produce beeps
print "So he said \a\a\a\a you"
print "So I said fuck\b\b\b\b\b **** you too!"
#tells printer to eject and start next page
print "form-feed? \f next page...?"

print "%sC%smo se dice?" % (begin_ques, accented_o)

print "tick tick tick tick"
print "tick tick \a\rtick tick" #second set of ticks not printed
#carriage return brings to start of line, overwrites with ws before linefeed
#and final tick
print "tick tick \a\r    \ntick tick"

#unicode hex replacement (16 bit)
print u"\u0231"
print u"\u2313"

#(32 bit)
print u"\U00000001"
print u"\U000000FF"

#when you tab vertically, next line begins where prev line ends
print "Vertical tab stair case"
print "Hello\vthere\vtab\vmadness!\vstraightness"
print "Hello\nthere\ntab\nmadness!\nstraightness"

#octal/hex char vals (72)_10 
#read from right to left! 
print "\110"
print "\x48"
