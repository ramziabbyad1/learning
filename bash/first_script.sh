#!/bin/bash
#
# Flush disks if nobody on computer
# 
# 
# Ramzi Abbyad
# CVS: $Header$
shopt -s -o nounset

#Global Declarations

declare -rx SCRIPT=${0##*/}
declare -rx who="/usr/bin/who"
declare -rx sync="/bin/sync"
declare -rx wc="/usr/bin/wc"


echo $SCRIPT
echo $who
echo $sync
echo $wc

#The template for a usual script

#header
#globals
#sanity-checks

if test -z "$BASH"; then
	printf "$SCRIPT:$LINENO: please run this script with BASH shell\n" >&2
	exit 192
fi
if test ! -x "$who" ; then
	printf "$SCRIPT:$LINENO: the command $who is not available - \
aborting\n" >&2
	exit 192
fi
if test ! -x "$sync"; then
	printf "$SCRIPT:$LINENO: the command $sync is not available - \
aborting\n" >&2
	exit 192
fi
if test ! -x "$wc"; then
	printf "$SCRIPT:$LINENO: the command $wc is not available - \
aborting\n" >&2
	exit 192
fi

#script body, flush disks if nobody is on the computer
USERS=`who | wc -l`
if [ $USERS -eq 0 ]; then
	sync
fi

#cleanup: temporary file delete, return status code
#more complicated code could use a variable for status code
exit 0 #all is well

suspend #wait until notified otherwise see job control and signals
sleep 5 #wait for 5 seconds
