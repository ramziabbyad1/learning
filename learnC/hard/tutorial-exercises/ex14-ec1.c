#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
	removing forward declaration confuses the compiler.
	for print letters, it only gives warnings. But for can_print_it,
	it produces an error.  possibly to do with the compiler assuming a certain 
	return type and then finding out it is wrong in the actual function 
	declaration.
*/
void print_letters(char arg[], int arrLen);
void print_numbers(char arg[], int arrLen);

void print_arguments(int argc, char *argv[]) 
{	
	int i = 0;
	for(i = 0; i < argc; i++) {
		printf("letters in argv[%d].. ", i);
		print_letters(argv[i], strlen(argv[i]));
		printf("numbers in argv[%d].. ", i);
		print_numbers( argv[i], strlen(argv[i]) );
	}
}
//Weird K&R way
void 
print_numbers(arg, arrLen)
			char arg[]; int arrLen;
{
	int i = 0;
	for(i = 0; i < arrLen; i++) {
		char ch = arg[i];
		if( isdigit(ch) ) {
			printf("'%c' = %d ", ch, ch);
		}
	}
	printf("\n");
}
//the correct way (standard c) of formatting fns
void 
print_letters(char arg[], int arrLen)
{
	int i = 0;
	for(i = 0; i < arrLen; i++) {
		char ch = arg[i];
		
		if(isalpha(ch) || isblank(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}


int main(int argc, char *argv[]) 
{
	//passing argc + 1 throws segfault
	print_arguments(argc, argv);
	return 0;
}
