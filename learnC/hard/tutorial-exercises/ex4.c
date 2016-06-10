#include <stdio.h>
/*
Broken version of ex3 to test valigrind.
*/

int main() 
{
	int age = 10;
	int height = 74;
	/*format specifier for unsigned long int
		i for int, prefixed with length specifier l for long/long unsigned
	*/
	printf("the size of the input is sizeof(age) = %li\n", sizeof(age));
	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height);

	return 0;
}
