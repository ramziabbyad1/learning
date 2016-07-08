#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//cpp constants
#define MAX_DATA 512
#define MAX_ROWS 100

/*
	Reworking the DB with global conn.  Result is nice,
	you don't have to pass it in everywhere (take for example die).
	Ideally, the next step is to come up with an Object system to avoid globals, 
	as globals make maintainability and collaboration harder.
*/

//fixed size struct representing an address
struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

//fixed-size representing the DB
struct Database {
	struct Address rows[MAX_ROWS];
};
//a reference to a file to read from 
//and a DB to write to
struct Connection {
	FILE *file;
	struct Database *db;
};

struct Connection *conn; //global connection, only changed a few lines

void Database_close();

//kill w error to stdout
//errno is set externally
//perror interprets errno #
void 
die(const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	Database_close();
	exit(1);
}

void
Address_print(struct Address *addr) 
{
	printf("%d %s %s\n",
		addr->id, addr->name, addr->email);
}

/*read one entire file
into database reference
FILE is just another struct
fread reads sizeof(struct Database) data 
into the connection database reference 
*/
void
Database_load()
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file );
	if(rc != 1) die("Memory Error!");
}

/*
	returns a reference to a connection
	must use reference to allocate memory that persists
	outside of the given function call
*/
struct Connection *
Database_open(const char *filename, char mode)
{
	conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error!");

	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error!");

	//create
	if(mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		//read or write
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			Database_load();
		}
	}

	if(!conn->file) die("File open failed.");

	return conn; //must return this to outside world somehow
}

//free connection and substructs
void
Database_close() 
{
	if(conn) {
		if(conn->file) fclose(conn->file);
		if(conn->db) free(conn->db);
		free(conn);
	}
}

//write db into file
void
Database_write()
{
	//reposition stream to beginning of file
	rewind(conn->file);

	//write to file from db
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to write to database.");

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush database");
}

//initialize database with empty records
void
Database_create()
{
	int i = 0;
	
	for(i = 0; i < MAX_ROWS; i++) {
		struct Address addr = { .id = i, .set = 0 };
	
		conn->db->rows[i] = addr;
	}
}
//set data on a database address
void
Database_set(int id, 
				const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id]; //assign ref to addr pointer
	if(addr->set) die("Already set, delete it first");

	addr->set = 1;
	//WARNING: bug, strncpy reads MAX_DATA bytes, if name is not null-term
	//neither is res
	char *res = strncpy(addr->name, name, MAX_DATA);

	if(!res) die("Name copy failed");	

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res) die("Email copy failed");
}

//print a db address records
void
Database_get(int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set");
	}
}

//set db address to empty data
void
Database_delete(int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

//print contents of db
void
Database_list()
{
	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
	
		if(cur->set) {
			Address_print(cur);
		}
	}
}


int
main(int argc, char *argv[])
{
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0]; //chars passed as string
	conn = Database_open(filename, action);
	//init a connection ref
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There aren't that many records.");

	switch(action) {
		case 'c': //init db and write it to file
			Database_create();
			Database_write();
			break;

		case 'g': //print rec from db
			if(argc != 4) die("Need an id to get");

			Database_get(id);
			break;

		case 's': //set rec in db, update file
			if(argc != 6) die("Need id, name, email to set");
			size_t name_sz = strlen(argv[4]);
			//printf("name_sz = %zd\n", name_sz);
			argv[4][name_sz] = '\0';
			Database_set(id, argv[4], argv[5]);
			Database_write();
			break;

		case 'd': //clear a rec by id, update file
			if(argc != 4) die("Need id to delete");

			Database_delete(id);
			Database_write();
			break;

		case 'l': //print db contents
			Database_list();
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(); //free memory
	return 0;
}
