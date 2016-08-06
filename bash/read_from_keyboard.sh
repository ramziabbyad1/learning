printf "Archive files for how many days? "
read ARCHIVE_DAYS
#note days doesn't have to be a number!
#equivalently

read -p "Archive files for how many days? " ARCHIVE_DAYS 

echo "ARCHIVE_DAYS = $ARCHIVE_DAYS"

#read input in raw form
read -p "Enter a Windows pathname (with backslashes): " -r MS_PATH

if test -z "$MS_PATH"; then
	echo "No path supplied form user."
else
	echo "MS_PATH = $MS_PATH"
fi
#from command line, can use -e to allow user interactive scrolling through hist

#for input timeout
read -p "Gimme a filename.." -t 5 FILENAME

#use max char length for var, if longer return
read -n 10 FILENAME


