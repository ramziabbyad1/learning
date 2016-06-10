#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
	Dynamically defined MAX_SIZE, MAX_ROWS
*/

//fixed size struct representing an address
struct Address {
	int id;
	int set;
	char *name;
	char *email;
};

//fixed-size representing the DB
struct Database {
	int MAX_ROWS;
	int MAX_DATA;
	struct Address *rows;
};
//a reference to a file to read from 
//and a DB to write to
struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn);

//kill w error to stdout
//errno is set externally
//perror interprets errno #
void 
die(const char *message, struct Connection *conn)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	Database_close(conn);
	exit(1);
}

void
Address_print(struct Address *addr) 
{
	printf("%d %d %s %s\n",
		addr->id, addr->set, addr->name, addr->email);
}

/*read one entire file
into database reference
FILE is just another struct
fread reads sizeof(struct Database) data 
into the connection database reference 
*/
void
Database_load(struct Connection *conn)
{
	//int *MAX_DATA, *MAX_ROWS;
	if(fread(&conn->db->MAX_DATA, sizeof(int), 1, conn->file) != 1) {
		die("Database load failed on reading MAX_DATA", NULL);
	}
	if(fread(&conn->db->MAX_ROWS, sizeof(int), 1, conn->file) != 1) {
		die("Database load failed on reading MAX_ROWS", NULL);
	}
	int rc;
	int MAX_DATA = conn->db->MAX_DATA;
	int MAX_ROWS = conn->db->MAX_ROWS;
	printf("I expect the size of an Address is 8+400 bytes = %ld\n", 
		2*sizeof(int)+2*MAX_DATA);
	rc = fread(&conn->db->rows, 2*sizeof(int) + 2*MAX_DATA, 
		MAX_ROWS, conn->file );
	printf("ROW[i].name = %s\n", conn->db->rows[0].name);
	if(!conn->db->rows) die("Rows not init..", conn);
	printf("MAX_ROWS = %d, MAX_DATA = %d, n_rows = %ld\n", conn->db->MAX_ROWS, 
		conn->db->MAX_DATA, sizeof(conn->db->rows));
	/*int MAX_ROWS = conn->db->MAX_ROWS;
	int MAX_DATA = conn->db->MAX_DATA;
	int read_sz = MAX_ROWS*MAX_DATA*2 + MAX_ROWS*sizeof(struct Address);
	rc = fread(conn->db, read_sz, 1, conn->file);*/
	if(rc != 1) die("Memory Error!", conn);
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
		die("Cannot print file.", NULL);
	}
}

/*
	returns a reference to a connection
	must use reference to allocate memory that persists
	outside of the given function call
*/
struct Connection *
Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error!", conn);

	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error!", conn);

	//create
	if(mode == 'c') {
		conn->file = fopen(filename, "w");
		//File_print(conn->file);
	} else {
		//read or write
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file) die("File open failed.", conn);
	puts("Returning connection");
	return conn; //must return this to outside world somehow
}

//free connection and substructs
void
Database_close(struct Connection *conn) 
{
	if(conn) {
		if(conn->file) fclose(conn->file);
		if(conn->db) {
			if(conn->db->rows) {
				int i = 0;
				for(; i < conn->db->MAX_ROWS; ++i) {
					if(conn->db->rows[i].set) {
						free(conn->db->rows[i].name);
						free(conn->db->rows[i].email);
					}
				}
				free(conn->db->rows);
			}
			free(conn->db);
		}
		free(conn);
	}
}

//write db into file
void
Database_write(struct Connection *conn)
{
	//reposition stream to beginning of file
	rewind(conn->file);

	//write to file from db
	int rc = fwrite(&conn->db->MAX_DATA, sizeof(int), 1, conn->file);
	rc = fwrite(&conn->db->MAX_ROWS, sizeof(int), 1, conn->file);
	int MAX_DATA = conn->db->MAX_DATA;
	int MAX_ROWS = conn->db->MAX_ROWS;
	fwrite(conn->db->rows, 2*sizeof(int) + 2*MAX_DATA, MAX_ROWS, conn->file);
	if(rc != 1) die("Failed to write to database.", conn);
	puts("writing db..");
	File_print(conn->file);

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush database", conn);
}

//initialize database with empty records
void
Database_create(struct Connection *conn)
{
	int i = 0;
	int MAX_ROWS = conn->db->MAX_ROWS;
	int MAX_DATA = conn->db->MAX_DATA;	

	conn->db->rows = malloc(MAX_ROWS*sizeof(struct Address));	

	for(i = 0; i < MAX_ROWS; i++) {
		struct Address addr = { 
			.id = i, .set = 0, .name = malloc(MAX_DATA), .email = malloc(MAX_DATA)
		};
		conn->db->rows[i] = addr;
		printf("Printing address at row %d\n", i);
		Address_print(&conn->db->rows[i]);
	}
}
//set data on a database address
void
Database_set(struct Connection *conn, int id, 
				const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id]; //assign ref to addr pointer
	addr->name = malloc(conn->db->MAX_DATA*sizeof(char));
	addr->email = malloc(conn->db->MAX_DATA*sizeof(char));
	printf("printing address\n");
	printf("address->name = %s\n", addr->name);
	Address_print(addr);
	if(addr->set) die("Already set, delete it first", conn);

	addr->set = 1;
	//WARNING: bug, strncpy reads MAX_DATA bytes, if name is not null-term
	//neither is res
	char *res = strncpy(addr->name, name, conn->db->MAX_DATA);

	if(!res) die("Name copy failed", conn);	

	res = strncpy(addr->email, email, conn->db->MAX_DATA);
	if(!res) die("Email copy failed", conn);
}

//print a db address records
void
Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set", conn);
	}
}

//set db address to empty data
void
Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

//print contents of db
void
Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < db->MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
	
		if(cur->set) {
			Address_print(cur);
		}
	}
}

int
main(int argc, char *argv[])
{
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params] <MAX_DATA> <MAX_ROWS>", NULL);
	char *filename = argv[1];
	char action = argv[2][0]; //chars passed as string
	if(action == 'c' && argc != 5) die("USAGE: <MAX_DATA> <MAX_ROWS>", NULL);
	//init a connection ref
	struct Connection *conn = Database_open(filename, action);
	if(action == 'c') {
		int MAX_DATA = atoi(argv[3]);
		int MAX_ROWS = atoi(argv[4]);
		conn->db->MAX_DATA = MAX_DATA;
		conn->db->MAX_ROWS = MAX_ROWS;
		
	}
	if(conn->db) {
		printf("MAX_DATA for this db: %d\n", conn->db->MAX_DATA);
	}
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= conn->db->MAX_ROWS) die("There aren't that many records.", conn);

	switch(action) {
		case 'c': //init db and write it to file
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g': //print rec from db
			if(argc != 4) die("Need an id to get", conn);

			Database_get(conn, id);
			break;

		case 's': //set rec in db, update file
			if(argc != 6) die("Need id, name, email to set", conn);
			size_t name_sz = strlen(argv[4]);
			//printf("name_sz = %zd\n", name_sz);
			argv[4][name_sz] = '\0';
			printf("writing name = %s\n", argv[4]);
			printf("writing email = %s\n", argv[5]);
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd': //clear a rec by id, update file
			if(argc != 4) die("Need id to delete", conn);

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l': //print db contents
			Database_list(conn);
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", 
				conn);
	}

	Database_close(conn); //free memory
	return 0;
}
