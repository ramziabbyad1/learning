#include <stdio.h>
//A simple conditional on args
int main(int argc, char *argv[]) 
{
	int i = 0;
	//args other than the program name
	int arg_count_true = argc - 1;
	if (arg_count_true == 0) 
	{
		printf ("You have zero arguments.  I hate you.\n");
	} 
	else if (arg_count_true < 3) 
	{
		printf ("Here're your arguments:\n");

		for(i = 1; i <= arg_count_true; i++) {
			printf ("%s ", argv[i]);
		}
		printf ("\n");
	} 
	else 
	{
		printf ("Too many arguments man..");
	}
	return 0;
}
