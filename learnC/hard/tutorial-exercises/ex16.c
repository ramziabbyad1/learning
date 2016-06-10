//import header files
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//POSIX is an library API that is a superset of the standard ansi c
//a standard defines a particular programming language's
//define struct (compound data type) on heap
struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

//declare a constructor 
struct Person *Person_create(char *name, int age, int height, 
								int weight) 
{
	//tell malloc to fetch memory
	struct Person *who = malloc(sizeof(struct Person));

	/*check for malloc failure
	 most obvious cause for this is probably out of memory error
		due either to allocating all available memory or heap fragmentation
	 or artificially limiting the address space using
	 void *malloc(size_t sz) {return NULL;}
	 or calling malloc(0) 
	*/
	assert(who != NULL);

	//assign properties of struct
	//strdup HIDES a call to malloc and must be freed!
	//also it is POSIX C, as opposed to ANSI C
	//thus, the C Standard could define its own strdup since str is a reserved
	//prefix.  Hence portability is a concern.
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void 
Person_destroy(struct Person *who)
{
	//make sure malloc didn't fail
	assert(who != NULL);

	//free all Person memory
	//name is also a pointer created by malloc
	//this is evident from the valgrind errors which trace back to
	//strdup from string.h, which uses malloc to duplicate the given string
	free(who->name);
	free(who);
}

void
Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int
main(int argc, char *argv[])
{
	/*create two sample Person's.  
	These guys go on the heap, their 
	addresses increase in order of creation*/
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
			"Frank Blank", 20, 72, 180);

	//print the address then print the Person
	printf("Joe is at memory location %p\n", joe);
	Person_print(joe);
	
	//Person_destroy(NULL);	//Assertion will abort program
	printf("Frank is at memory location %p\n", frank);
	Person_print(frank);

	//change the properties of the Person's and print the changes
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	//destory the Persons when done
	//Person_destroy(joe); //commenting destroy produces mem leak
	//running valgrind with --leak-check=full shows errors traced
	//to the moment of struct Person creation (malloc)
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
