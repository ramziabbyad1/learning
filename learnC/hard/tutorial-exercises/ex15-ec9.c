#include <stdio.h>
/*
	Printing the ex15 data using functions and while loops v. for loops
*/

void 
print_names_ages(char *format_str, char **names, int *ages, int size) 
{
	int i = 0;
	for(
		; 
		i < size; 
		printf(format_str, names[i], ages[i]), i++
	);

	printf("---\n");	
}

void 
print_names_ages_while(char *format_str, char **names, int *ages, int size) 
{
	int i = 0;
	while( i < size ) { 
		printf(format_str, names[i], ages[i]), i++;
	}
	

	printf("---\n");	
}

void
print_using_offsets(char **names, int *ages, int count) 
{
	int *curr_age = ages;
	char **curr_name = names;
	int i = 0;
	for(; i < count; i++) {
		printf("%s is %d years old.\n",
				*(curr_name + i), *(curr_age + i));
	}

	printf("---\n");	
	
}

void
print_using_offsets_while(char **names, int *ages, int count) 
{
	int *curr_age = ages;
	char **curr_name = names;
	int i = 0;
	while( i < count ) {
		printf("%s is %d years old.\n",
				*(curr_name + i), *(curr_age + i)), i++;
	}

	printf("---\n");	
	
}

void
print_using_p_arith(char **names, int *ages, int count) 
{
	int *curr_age = ages;
	char **curr_name = names;
	//too much pointer arithmetic not a good way
	for(curr_name = names, curr_age = ages;
		(curr_age - ages) < count;
		curr_name++, curr_age++)
	{
		printf("%s lived %d years so far.\n",
				*curr_name, *curr_age);
	}

	printf("---\n");	
}

void
print_using_p_arith_while(char **names, int *ages, int count) 
{
	int *curr_age = ages;
	char **curr_name = names;

	//too much pointer arithmetic not a good way
	while( (curr_age - ages) < count )
	{
		printf("%s lived %d years so far.\n",
				*curr_name, *curr_age),
		curr_name++, curr_age++;
	}

	printf("---\n");	
}

int
main(int argc, char *argv[]) 
{
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Liz"
	};	
	
	int count = sizeof(ages)/sizeof(int);
	int i = 0;

	char *format_str = "%s has %d years alive.\n";

	//Do printing using functions

	print_names_ages(format_str, names, ages, count);
	print_names_ages_while(format_str, names, ages, count);

	print_using_offsets(names, ages, count);
	print_using_offsets_while(names, ages, count);

	print_using_p_arith(names, ages, count);
	print_using_p_arith_while(names, ages, count);

	for(i = 0; i < count; i++) {
		printf("&ages[%d] = %p\n", i, &ages[i]);
	}

	/*
		&ages[0] = 0x7fffe06edb50
		&ages[1] = 0x7fffe06edb54
		&ages[2] = 0x7fffe06edb58
		&ages[3] = 0x7fffe06edb5c
		&ages[4] = 0x7fffe06edb60
		
		cool! each address 4 greater than the one before in hex
		that is, 4 bytes to and int. I guess pointers are store on the heap
		since the addresses increment from ages to names

		now here is a char array
		
	*/
	int names_0_len = 4;
	for(
		i = 0; i < names_0_len; 
		printf("&names[0][%d] = %p\n", i, &names[0][i]), i++
	);

	/*
		as expected addresses differ by one byte, the len of a char
		&names[0][0] = 0x400854
		&names[0][1] = 0x400855
		&names[0][2] = 0x400856
		&names[0][3] = 0x400857
	*/	

	//the next example is the most interesting
	for(i=0; i < count; printf("&names[%d] = %p\n", i, &names[i]), i++);
	//.. outputs an address, address + 8, address + 2, address+8, etc
	//this tells me the number 10 bytes is somehow important

	return 0;
}
