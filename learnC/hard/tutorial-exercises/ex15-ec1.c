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
	//this works too, but you need a cast, otherwise it's reference to array 
	// &ages means reference to const int
	int *pointer_test = (int *)&ages;	
	for(i=0; i < count;  printf("ages[i] = %d\n", *(pointer_test+i)),  i++);
	
	//pointers to starts of arrays
	int *curr_age = (int *) names; 
	// initialization from incompatible pointer type w/o cast
	
char **curr_name = names;
	printf("names is assigned to curr_age\n");
	printf("(char *)[] -> (int *)\n"); //prints numbers, perhaps chars in names
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
		curr_name+=2, curr_age+=2)
	{
		printf("%s lived %d years so far.\n",
				*curr_name, *curr_age);
	}
	
	return 0;
}
