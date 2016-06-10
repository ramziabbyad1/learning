#include <stdio.h>

/*Adding break statements to ex10*/
int main(int argc, char *argv[]) 
{
	int i = 0;


	//a string array!
	char *states[] = {
		"California", "Oregon", //NULL, it just prints (null)
		"Washington", "Texas"
	};

	/*
		NULL is a value.  It is the default value assigned to a pointer of a specific type.  
		For example (int *) or (char *) have different NULL values assigned to them.  
		Conceptually, NULLs signify pointers that don't point anywhere.  
		They are used as markers, such as to mark the end of a linked list.
	*/
	
	argv[1] = states[2];
	states[2] = argv[3];

	//go through the string array argv, skipping script name
	for(i = 0; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
		if(i > 2) {
			break;
		};
	} //note this loop is skipped if no args are supplied

	/*if pushed past length of states, it shows (null) garbage (null) garbage, etc until a segfault*/
	int num_states = 6;

	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

	int j = 0, k = 0, n = 9;
	for(
		/*
			int j = 0, int n = 9, k = 0;  
			//initial declarations only allowed in c99 mode
		*/
		;
		(j*j< n ) && k <= 5; 
		printf ("k is now %d\n", k), k++, j++
	);
	
	return 0;
}
