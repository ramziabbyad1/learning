#include <stdio.h>

//Adding break statements to ex11
//argv holds some intriguing info if run with no args
//like XDG_VTNR, XDG_SESSION_ID=c2 
int main(int argc, char *argv[]) 
{
	int i = 0;
	while (i < argc) {
		printf("arg %d: %s\n", i, argv[i]);
		if( i > 3 ) { break; }
		i++;
	}

	puts("print em' backwards..");

	i = argc - 1;
	while(i >= 0) {
		printf("arg %d: %s\n", i, argv[i]);
		i--;	
	}

	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

/*
	//copy argv into states

	i = 1;
	while(i <= argc) {
		states[i-1] = argv[i];
		i++;
	}
*/

	int num_states = 4;
	//safe limited copy argv into states
	puts("copy into states from argv");
	for(i=1; i <= num_states; i++) {
		states[i-1] = argv[i];
		if(i == 3) { break; }
	}

	i = 0;
	while (i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;
	}
	puts("print 'em backwards");
	i = num_states - 1;
	while(i >= 0) {
		printf("state %d: %s\n", i, states[i]);
		if (i == 2) { break; }
		i--;
	}


	return 0;
}
