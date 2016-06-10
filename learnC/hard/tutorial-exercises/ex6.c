#include <stdio.h>

/*A program to play with different variable types*/
int main(int argc, char *argv[]) 
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Ramzi";
	char last_name[] = "Abbyad";
	
	//play with format specifiers
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("My whole name is %s %c. %s. \n", 
		first_name, initial, last_name);

	//extra credit exercises with printf
	/*
		note %*d skips the current %d param and goes to the next one
		this way you don't have to write multiple % 
	*/
	printf("%*d %*d \n", 1, 2, 3, 4); //2 4
	/*
		%m$ allows to get param by index, * skips as usual
		note this format must be used consistently
		also, args 1, 3 can only be used if 2 is used (no gaps)
	*/
	printf("%2$*1$d %3$d \n", 1, 2, 3); //2 3
	/*
		use of radix character (POSIX) and length
		" ' " is a flag for grouping thousands character (doesn't work with this compiler)
	*/
	printf("%'.2f \n", 12234.1234); //12234.12
	printf("%'d \n", 123456);
	// # convert output to 0 prepended
	printf("%#o \n", 8); //octal 10 will be 010
	printf("%#x \n", 0xFF); // 0xff	
	printf("%x \n", 0xFF);	// ff
	printf("%#X \n", 0xFF); // 0xFF

	//0 flag does 0 padding, overrided by length specifiers
	printf("%05x \n", 0x00100000); //exeeds 5 length 100000
	printf("%010x \n", 0x10000); //initial 0's

	printf(""); //issues compiler warning for 0 length format string
	printf(" \n");
	puts(""); //no warning
	/*
		TODO: finish printf man 3 page
	*/

	return 0;
	
}
