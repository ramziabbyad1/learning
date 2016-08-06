#!/bin/bash

shopt -s -o nounset

ls -l incoming/orders
ls -l incoming/orders 1>&1
ls -l incoming/orders >/dev/tty

bash listorders.sh 1> listings.txt #errors do not kill execution!
bash listorders.sh 2> listings_errors.txt #take 2 file and redirect
bash listorders.sh >&2

bash listorders.sh > listorders_errors.txt >&2 #indirect redirection
bash listorders.sh &>> listorders_errors.txt #shorthand for redirecting both



exit 0
