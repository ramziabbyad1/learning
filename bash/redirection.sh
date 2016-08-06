printf "The processing is complete\n" > results.txt
printf "There were no errors" >> results.txt

wc --lines < results.txt

who | wc --lines

wc --lines << START_OF_LIST
	jones, allen
	grates, william
	oregano, percy
START_OF_LIST


