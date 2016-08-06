printf "Sales are up \n" > /dev/tty #screen = tty file, send directly

printf "Sales are up \n" #send through stdout

printf "Sales are up \n" >&1 #same

printf "Sales are up \n" >/dev/stdout #send to stdout

#printf "Sales are up \n" #send through stdout
