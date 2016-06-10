#include <stdio.h>
#include <ctype.h>
/*
	removing forward declaration confuses the compiler.
	for print letters, it only gives warnings. But for can_print_it,
	it produces an error.  possibly to do with the compiler assuming a certain return type and then finding out it is wrong in the actual function declaration.:
*/
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]) 
{	
	int i = 0;
	for(i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;
	for(i = 0; arg[i] != '\0'; i++) {
		char ch = arg[i];
		
		if(can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]) 
{
	//passing argc + 1 throws segfault
	print_arguments(argc, argv);
	return 0;
}
