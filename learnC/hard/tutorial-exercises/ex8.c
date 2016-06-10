#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	//name[3] = '0'; // no longer null terminated.. no problem for printf
	//however, valgrind complains of writing to a restricted area
	char full_name[] = {
		'Z', 'e', 'd', ' ',
		'A', '.', ' ', 'S',
		'h','a','w', '\0'
	}; //can get rid of valgrind errors by null-terminating
	//take note of %ld's
	name[0] = full_name[2];
	areas[1] = full_name[3]; //c doesn't know the difference! they are both the same size.
	printf("The size of an int: %ld \n", sizeof(int));
	printf("The size of areas (int[]): %ld \n", 
		sizeof(areas));
	printf("The number of ints in areas: %ld \n",
		sizeof(areas)/sizeof(int));
	printf("The first area is %d, the Second %d \n",
		areas[/*1*/0], areas[1]); //array out of bounds access doesn't throw an error! valgrind complains of uninitialized value

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", 
		sizeof(name));
	printf("The number of chars: %ld\n", 
		sizeof(name)/sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
		sizeof(full_name));
	printf("The number of chars: %ld\n", 
		sizeof(full_name)/sizeof(char));
	printf("full_name = %s\n", full_name);	//This appears as valgrind bug
	printf("name=\"%s\" and full_name=\"%s\" \n",
		name, full_name);		
	
	return 0;
}
