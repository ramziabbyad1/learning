#include <stdio.h>
/*
	printf, and breaking printf
*/
int main() {
	//int age; //<- same effect as removing age from printf call
	//float age = 10; //<- compiler warning prints 0, err output
	//char age = 10; //char == unsigned int in C/C++, no error
	int age = 10;
	int height = 72;

	//printf("I am %d years old.\n"); //<-generates compiler warning and prints nonsense
	//printf("I am years old.\n", age); //<-compiler warning normal output but with no age
	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height);

	return 0;
}