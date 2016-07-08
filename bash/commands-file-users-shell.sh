#############ls#######################
ls -A #list all files including hidden
ls -a #list all files including ., ..
ls --color=never --classify #no dir_colors, classify by file type

rm orders.txt #rm: orders.txt non-existent
ls --color=never --classify --hide-control-chars
#output: archive/ check-orders.sh* orde?rs.txt

#############printf#####################
printf "%d\n" 5 #5
printf "%f\n" 5 #5.000000

printf "There are %d customers with purchases over %d.\n" 50 20000
#There are 50 customers with purchases over 20000
ERRMSG="Howdy Partner"
printf "%s\n" "$ERRMSG" | tr [:lower:] [:upper:]
#convert lower to upper

tr [:lower:] [:upper:] <<< "$ERRMSG";
##<<< shortcut redirect

printf "%o\n" 10; #prints 12, converts decimal to octal
printf "%s in hex = %a\n" "1.2" 1.2 #converts float to hex
printf "%s in hex = %a\n" "10.3221" 10.3221 #converts float to hex
printf "or, in uppercase\n"
printf "%s in hex = %A\n" "10.3221" 10.3221 #converts float to hex
#printf "%b" same as printf "%s" as far as i can tell..

printf "char Q = %c\n" 'Q'
printf "%d\n" -1000
printf "scientific notation %f = %e\n" 1200.2233 1200.2233
printf "%f = %g %f = %g\n" 123 123 12345678910 12345678910
#above automatically chooses %f or %e for ints!
printf "%%i = %%d <=> %i = %d\n" 234 234
printf "octal of %d = %o\n" 12 12
printf "using %%b ... %b\n" "\"howdy\""
printf "using %%s ... %s\n" "\"howdy\""
printf "quotes = %q\n" "\"howdy\""
printf "%u =? %d\n" -10 -10 #prints garbage, underflow
printf "hex : %x = %d\n" 1234
printf "HEX : %X = %d\n" 1234
printf "\"printf\" respects ranges and prints warning\n"
printf "%d\n" 123456789123456789012
printf "Here is a signed int in a 10 char column..\n"
printf "%10d\n" 11
printf "A negative number left-justifies\n"
printf "%-10d %-10d\n" 11 12
printf "%%10.5f uses a 10 char column with min 5 decimal digits\n"
printf "%10.5f\n" 17.2
printf "%%'f\n"
printf "%'f\n" 16000.2
printf "ASCII 65 (octal 101) is the character \O101\n"

#if aliases are used in a shell command, they are expanded upon shell function def, not runtime

bind -P -m vi | head -5 #bind, show key-map bindings, through bash with edit mode -m, you can set command abortion, as well as other keyboard signals

bind -l; bind -P #first lists function names, second lists names and keymaps

bind -S #lists keyboard macros
bind "\C-w:\" >/dev/null\"" #inserts >/dev/null into current line
bind -S

echo "shopt login_shell"
shopt login_shell #says on
bash --login #check profile changes at ~/.profile

shopt -o emacs
bash #starts a new shell session without logging in and thus does not run the .profile file
logout; exit #logout doesn't work

bash --norc #new bash with no resources
logout

