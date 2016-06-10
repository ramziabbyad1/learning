#include <stdio.h>

int main() 
{
	char* full_name = (char*)malloc(sizeof(char)*5);
	full_name[0] = 'R';
	full_name[1] = 'a';
	full_name[2] = 'm';
	full_name[3] = 'z';
	full_name[4] = 'i';
	//full_name = {'R', 'a', 'm', 'z', 'i'};
	printf("My name is %s\n", full_name);
	puts(full_name);
	free(full_name);
	return 0;
}
