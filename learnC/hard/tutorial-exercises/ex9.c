#include <stdio.h>

/*Arrays and strings exercise*/
int main(int argc, char *argv[]) {
	//initializing an element initialized rest to 0
	int numbers[4] = {0}; //you can assign length as 4 and initialiser as length 1, don't think it's possible in java
	
	char name[4] = {'a'}; //like int array the others elems are inited to 0
	//char name[4] = {'a', 'b', 'c', 'd', 'e'}; //compiler complains, also you cannot access the additional element e in anyway, you are probably overwriting some other part of memory
	//char *name = "000"; //this will cause segfault due to array assignment.  string literals are immutable equivalent to  cont char[]

	char zeros[4] = {0};
	//printf("numbers as string? : %s\n", numbers); //prints nothing! compiler complains of wrong type for printf
	printf("zeroes each: %c %c %c %c\n", zeros[0], zeros[1],
		zeros[2], zeros[3]); //prints nothing also!
	printf("zeros as string: %s\n", zeros); //nothing, 0 is a space
	printf("numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c \n",
		name[0], name[1], name[2], name[3]/*, name[4]*/); //no run time error for char[] of length 4, valgrind will catch it though as illegal buffer write in printf

	printf("name: %s\n", name);

	numbers[0] = 1;	
	numbers[1] = 2;	
	numbers[2] = 3;	
	numbers[3] = 4;

	name[0] = 'Z';	
	name[1] = 'e';	
	name[2] = 'd';	
	name[3] = '\0';
	//name[3] = 'a'; //valgrind complains of overwriting printf buffer


	printf("numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("name: %s\n", name);

	char *another = "Zed"; //final initialize for a string = (char *)

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n", 
		another[0], another[1],
		another[2], another[3]);

/*
	//assign int array to chars valgrind doesn't like it, as ints are larger than chars and hence there are buffer overwrite issues
	name[0] = numbers[0];
	name[1] = numbers[1];
	name[2] = numbers[2];
	name[3] = numbers[3];

	printf("name each: %c %c %c %c\n",
		name[0], name[1], name[2], name[3]);

	printf("name: %s\n", name);
*/
	
	//what about treating elems of names as ints in the format string?
	printf("each name as int: %d %d %d %d\n", name[0], name[1],
		name[2], name[3]);//no compiler or runtime/valgrind errors

	//..or numbers as chars..
	printf("each number as char: %c %c %c %c\n", numbers[0], numbers[1],
		numbers[2], numbers[3]);	//no compiler or runtime/valgrind errors.  I suspect it works as numbers[i] is truncated to a char

	//..or numbers as string?
	//printf("numbers as a string: %s\n", numbers); //printf expect char *, not int * says compiler no valgrind errors

	//assign chars to array of ints
	numbers[0] = name[0];
	numbers[1] = name[1];
	numbers[2] = name[2];
	numbers[3] = name[3];

	//no compiler warnings no valgrind or runtime errors
	printf("numbers each after char assign: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	//we are able to cast a char pointer to an int pointer :)
	int *name_as_number = (int *)name; //compiler warns of a cast, so let's use it

	printf("The number representation of the 4 bytes in name give: name = %i\n",
		name_as_number[0]);

	return 0;	
}
