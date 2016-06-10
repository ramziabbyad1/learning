#include <stdio.h>
/*Ex13 with pointer increment*/
int 
main(int argc, char **argv)
{
	if(argc != 2) {
		printf("ERROR: You need on argument.\n");
		return 1;
	}
	
	int i = 0;
	char *str = *(++argv);
	for(i = 0; *str != '\0'; str++) {
		char letter = *(str);
		
		switch(letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break; //eliminating the break causes unintended fallthrough
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;
			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;
			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;
			case 'y':
			case 'Y':
				if(i > 2) {
					printf("%d: 'Y'\n", i);
				}
				break;
			default: //eliminating default causes it to miss consonants
				printf("%d: %c is not a vowel\n", i, letter);
				break;
		}
	}

	return 0;
}
