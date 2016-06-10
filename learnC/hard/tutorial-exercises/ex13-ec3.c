#include <stdio.h>
//Substitute if-else for case statement
//easier to debug, more compact, generally better
int main(int argc, char *argv[])
{
	if(argc == 1) {
		printf("ERROR: You need at least argument.\n");
		return 1;
	}

	int argk = 1;
	for(; argk < argc; argk++) {
		int i = 0;
		char letter;
		for(
			i = 0, letter = argv[argk][i]; 
			argv[argk][i] != '\0'; 
			i++, letter = argv[argk][i]
		) {
			if(letter >= 65 && letter <= 122) {
				if( (letter + 32) <= 122 ) {
					letter += 32;
				}
			}
			 
			if(letter == 'a') {
				printf("%d: 'A'\n", i);
			}
			else if( letter == 'e'){
				printf("%d: 'E'\n", i);
			}
			else if( letter == 'i') {
				printf("%d: 'I'\n", i);
			}
			else if( letter == 'o') {
				printf("%d: 'O'\n", i);
			}
			else if( letter == 'u') {
				printf("%d: 'U'\n", i);
			}
			else if( letter == 'y') {
				if(i > 2) {
					printf("%d: 'Y'\n", i);
				}
			}
			else { 
				printf("%d: %c is not a vowel\n", i, letter);
			}
		}
	}

	return 0;
}
