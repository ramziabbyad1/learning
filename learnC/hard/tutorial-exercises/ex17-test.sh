#!/bin/bash

set -e

declare -rx SCRIPT=${0##*/}

declare -rx DB_FILE_STATIC="db-test-static.dat"
declare -rx EMPTY_SIZE=103200

declare -rx TEST_ROWS_1=500
declare -rx TEST_DATA_1=128
declare -rx DB_DYNAMIC_1="db-test-1.dat"
declare -rx ROW_SIZE_1=8 + 2*$TEST_DATA_1
declare -rx EMPTY_SIZE_1=$TEST_ROWS_1*$ROW_SIZE_1

declare -rx TEST_ROWS_2=5000
declare -rx TEST_DATA_2=1024
declare -rx DB_DYNAMIC_2="db-test-2.dat"
declare -rx ROW_SIZE_2=12 + 2*$TEST_DATA_2
declare -rx EMPTY_SIZE_2=$TEST_ROWS_2*$ROW_SIZE_2


if test -z "$BASH"; then
	printf "$SCRIPT:$LINENO: please run this script with BASH shell\n" >&2
	exit 192
fi

#TESTING STATIC DB

printf "CREATING STATIC DB IN: $DB_FILE_STATIC\n\n"
#create db
./ex17 $DB_FILE_STATIC c

STATIC_DB_SIZE=`stat -c%s $DB_FILE_STATIC` 
if test  $STATIC_DB_SIZE -ne $EMPTY_SIZE; then
	printf "The newly created db $DB_FILE_STATIC\
		is not the expected size.. \n\n
	"
	exit 192
fi

printf "SETTING MOCK RECORDS\n\n"
#set records
./ex17 $DB_FILE_STATIC s 0 zero zero@zero.com
./ex17 $DB_FILE_STATIC s 3 three three@three.com
./ex17 $DB_FILE_STATIC s 8 eight eight@eight.com
./ex17 $DB_FILE_STATIC s 98 one-hundred-and-ninety-eight one-hundred-and-ninety-eight@one-hundred-and-ninety-eight.com
./ex17 $DB_FILE_STATIC s 99 one-hundred-and-ninety-nine one-hundred-and-ninety-nine@one-hundred-and-ninety-nine.com

STATIC_DB_SIZE=`stat -c%s $DB_FILE_STATIC`
printf "size of db after setting 5 records = %d\n" $STATIC_DB_SIZE

printf "LISTING MOCK RECORS\n\n"

./ex17 $DB_FILE_STATIC l

#CLEARING MOCK DATA

printf "\n\nCLEARING MOCK RECORDS\n\n"

./ex17 $DB_FILE_STATIC d 0 
./ex17 $DB_FILE_STATIC d 3 
./ex17 $DB_FILE_STATIC d 8 
./ex17 $DB_FILE_STATIC d 98 
./ex17 $DB_FILE_STATIC d 99 

printf "AN EMPTY DATABASE\n\n"

./ex17 $DB_FILE_STATIC l

############TESTING DYNAMIC 1#####################

printf "CREATING DYNAMIC DB IN: $DB_DYNAMIC_1\n\n"
printf "MAX_DATA : $MAX_DATA   MAX_ROWS : $MAX_ROWS \n\n"
#create db
./ex17-ec1 $DB_DYNAMIC_1 c $TEST_DATA_1 $TEST_ROWS_1 

printf "SETTING MOCK RECORDS\n\n"
#set records
./ex17-ec1 $DB_DYNAMIC_1 s 0 zero zero@zero.com
./ex17-ec1 $DB_DYNAMIC_1 s 3 three three@three.com
./ex17-ec1 $DB_DYNAMIC_1 s 8 eight eight@eight.com
./ex17-ec1 $DB_DYNAMIC_1 s 498 one-hundred-and-ninety-eight one-hundred-and-ninety-eight@one-hundred-and-ninety-eight.com
./ex17-ec1 $DB_DYNAMIC_1 s 499 one-hundred-and-ninety-nine one-hundred-and-ninety-nine@one-hundred-and-ninety-nine.com

printf "LISTING MOCK RECORS\n\n"

./ex17-ec1 $DB_DYNAMIC_1 l

printf "CLEARING MOCK RECORDS\n\n"

./ex17-ec1 $DB_DYNAMIC_1 d 0 
./ex17-ec1 $DB_DYNAMIC_1 d 3 
./ex17-ec1 $DB_DYNAMIC_1 d 8 
./ex17-ec1 $DB_DYNAMIC_1 d 498 
./ex17-ec1 $DB_DYNAMIC_1 d 499 

printf "AN EMPTY DATABASE\n\n"

./ex17-ec1 $DB_DYNAMIC_1 l



#clean up
rm $DB_FILE_STATIC
rm $DB_DYNAMIC_1
rm $DB_DYNAMIC_2
