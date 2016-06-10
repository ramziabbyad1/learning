#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Address {
	int id;
	int set;
	char *name;
	char *email;
	int max_len;
};

void 
die(const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

void
File_print(FILE *file) 
{
	int c;
	if(file) {
		while( (c = getc(file)) != EOF) {
			putchar(c);
		}
	}
	else {
		die("Cannot print file.");
	}
}

void
test_write(FILE *file, struct Address *addr)
{
	//reposition stream to beginning of file
	rewind(file);

	//write to file from db
	printf("The size of file will be %ld\n", sizeof (struct Address));
	printf("The size of name will be %d\n", addr->max_len);
	/*int rc = fwrite(&addr->id, sizeof(int), 1, file);
	rc = fwrite(&addr->set, sizeof(int), 1, file);
	rc = fwrite(&addr->max_len, sizeof (int), 1, file);
	rc = fwrite(addr->name, addr->max_len, 1, file);
	rc = fwrite(addr->email, addr->max_len, 1, file);*/
	int rc = fwrite(&addr->id, sizeof(int), 1, file);
	if(rc != 1) die("Failed to write to database.");
	//puts("writing db..");
	//File_print(file);

	rc = fflush(file);
	if(rc == -1) die("Cannot flush database");
}

int
main()
{
	printf("sizeof addr = %ld\n", sizeof(struct Address*));
	struct Address *addr;
	addr = malloc(32);
	if(addr == NULL) die("addr null");
	addr->id = 0;
	addr->set = 10;
	printf("addr->id = %d\n", addr->id);
	printf("addr->set = %d\n", addr->set);
	addr->name = malloc(10*sizeof(char));
	addr->email = malloc(10*sizeof(char));
	size_t max_len = 10*sizeof(char);
	addr->max_len = max_len;
	printf("size addr->name = %ld\n", max_len);
	printf("size addr->email = %ld\n", max_len);
	addr->name[0] = 'c';
	addr->name[1] = '\0';
	addr->email[0] = 'e';
	addr->email[1] = '\0';
	//strncpy(addr->name, "santa c\0", max_len);
	//strncpy(addr->email, "santa@\0", max_len);
	printf("addr->name = %s\n", addr->name);
	printf("addr->email = %s\n", addr->email);

	FILE *file;
	file = fopen("pointer_test.dat", "w");
	test_write(file, addr);	
	fclose(file);

	free(addr->name);
	free(addr->email);
	free(addr);
//	free(file);
	return 0;
}
