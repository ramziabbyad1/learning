#include <stdio.h>
#include <stdlib.h>
/*
	Changing all pointers to arrays
*/
int
main(int argc, char *argv[]) 
{
	//make everything pointy
	int ages[5];
	ages[0] = 23;
	ages[1] = 43;
	ages[2] = 12;
	ages[3] = 89;
	ages[4] = 2;
	char *names[5];
	names[0] = "Alan";
	names[1] = "Frank";
	names[2] = "Mary";
	names[3] = "John";
	names[4] = "Liz";
	
	int count = sizeof(ages)/sizeof(int);
	int i = 0;

	for(i = 0; i < count; i++) {
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	printf("---\n");
	//this works too, but you need a cast, otherwise it's reference to array 
	// &ages means reference to const int
	int pointer_test[5];
	for(i=0; i < count; pointer_test[i] = ages[i], i++);	
	for(i=0; i < count;  printf("ages[i] = %d\n", *(pointer_test+i)),  i++);
	
	//char **curr_name = names;
	char *curr_name[5];
	for(i=0; i < count; curr_name[i] = names[i], i++);
	int curr_age[5];
	for(i=0; i < count; curr_age[i] = ages[i], i++);
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
/*
As far as arrays you can't really use this part

	//too much pointer arithmetic not a good way
	for(curr_name = names, curr_age = ages;
		(curr_age - ages) < count;
		curr_name+=2, curr_age+=2)
	{
		printf("%s lived %d years so far.\n",
				*curr_name, *curr_age);
	}
*/
	
	return 0;
}
