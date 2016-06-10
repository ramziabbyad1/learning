#include <stdio.h>

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

	for(i = 0; i < count; i++) {
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	printf("---\n");
	
	//pointers to starts of arrays
	int *curr_age = ages;
	char **curr_name = names;

	for(i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
				*(curr_name + i), *(curr_age + i));
	}

	printf("---\n");	

	for(i = 0; i < count; i++) {
		printf("%s is %d years old again.\n",
				curr_name[i], curr_age[i]);
	}

	printf("---\n");

	//too much pointer arithmetic not a good way
	for(curr_name = names, curr_age = ages;
		(curr_age - ages) < count;
		curr_name++, curr_age++)
	{
		printf("%s lived %d years so far.\n",
				*curr_name, *curr_age);
	}

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
		that is, 4 bytes to and int.

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
