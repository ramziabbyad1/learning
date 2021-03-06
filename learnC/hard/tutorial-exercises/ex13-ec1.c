#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc == 1) {
		printf("ERROR: You need at least argument.\n");
		return 1;
	}
	printf("A = %d\n", 'A');	
	printf("a = %d\n", 'a');
	printf("B = %d\n", 'B');	
	printf("b = %d\n", 'b');
	printf("Z = %d\n", 'Z');	
	printf("z = %d\n", 'z');
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
			 
			switch(letter) {
				case 'a':
					printf("%d: 'A'\n", i);
					break; //eliminating the break causes unintended fallthrough
				case 'e':
					printf("%d: 'E'\n", i);
					break;
				case 'i':
					printf("%d: 'I'\n", i);
					break;
				case 'o':
					printf("%d: 'O'\n", i);
					break;
				case 'u':
					printf("%d: 'U'\n", i);
					break;
				case 'y':
					if(i > 2) {
						printf("%d: 'Y'\n", i);
					}
					break;
				default: //eliminating default causes it to miss consonants
					printf("%d: %c is not a vowel\n", i, letter);
					break;
			}
		}
	}

	return 0;
}
