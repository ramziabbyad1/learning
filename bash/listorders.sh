#!/bin/bash

shopt -s -o nounset

ls -l incoming/orders
ls -l incoming/orders 1>&1
ls -l incoming/orders >/dev/tty

ls -lP #throw an error for output errors

exit 0
