#formatter = "%r %r %r %r"
formatter = "%r " * 4 #this works too!

print formatter % (1, 2, 3, 4)
print formatter % ("one", "two", "three", "four")
print formatter % (True, False, False, True)
print formatter % (formatter, formatter, formatter, formatter)
print formatter % (
	"I had this thing.",
	"Tat you could type up right.",
	"But it didn't sing.",
	"So I said goodnight"
)
