#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
	Dynamically defined MAX_SIZE, MAX_ROWS
	The size of our empty database is MAX_ROWS*(4 + 4) + 2 = 8*MAX_ROWS + 8
	if MAX_ROWS = 200 => empty_size = 1608
	every time we add a row we add 1024 bytes to the size
*/

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
	struct Address **rows;
};
//a reference to a file to read from 
//and a DB to write to
struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_list(struct Connection *conn);
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
	
	printf("%d %s %s\n",
		addr->id, addr->name == NULL ? "NULL" : addr->name, 
			addr->email == NULL ? "NULL" : addr->email );
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
	int rc = fread(&conn->db->MAX_DATA, sizeof(int), 1, conn->file);
	if(rc != 1) die("Memory Error!", conn);
	int MAX_DATA = conn->db->MAX_DATA;

	rc = fread(&conn->db->MAX_ROWS, sizeof(int), 1, conn->file);
	if(rc != 1) die("Memory Error!", conn);
	int MAX_ROWS = conn->db->MAX_ROWS;

	conn->db->rows = 
		(struct Address **) malloc(sizeof(struct Address *)*MAX_ROWS);

	int i = 0;
	for(; i < conn->db->MAX_ROWS; ++i) {
		
		conn->db->rows[i] = 
			(struct Address *) malloc(sizeof(struct Address));
		rc = fread(&conn->db->rows[i]->id, 
					sizeof(int), 
					1, 
					conn->file
				);
		if(rc != 1) die("Memory Error!", conn);

		rc = fread(&conn->db->rows[i]->set, 
					sizeof(int), 
					1, 
					conn->file
				);
		if(rc != 1) die("Memory Error!", conn);

		if(conn->db->rows[i]->set) {

			conn->db->rows[i]->name = 
				(char *) malloc(MAX_DATA * sizeof(char));
			rc = fread(conn->db->rows[i]->name, 
						sizeof(char)*MAX_DATA, 
						1, 
						conn->file
					);
			if(rc != 1) die("Memory Error!", conn);

			conn->db->rows[i]->email = 
				(char *) malloc(MAX_DATA * sizeof(char));
			rc = fread(conn->db->rows[i]->email, 
						sizeof(char)*MAX_DATA, 
						1, 
						conn->file
					);
			if(rc != 1) die("Memory Error!", conn);
		}
	}
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
	struct Connection *conn = 
		(struct Connection *) malloc(sizeof(struct Connection));
	if(!conn) die("Memory error!", conn);

	conn->db = (struct Database *) malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error!", conn);

	//create
	if(mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		//read or write
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file) die("File open failed.", conn);
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
					if(conn->db->rows[i]->set) {
						free(conn->db->rows[i]->name);
						free(conn->db->rows[i]->email);
					}
					free(conn->db->rows[i]);
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
	int MAX_DATA = conn->db->MAX_DATA;
	int rc = fwrite(&conn->db->MAX_DATA, sizeof(int), 1, conn->file);
	if(rc != 1) die("Failed to write to database.", conn);
	rc = fwrite(&conn->db->MAX_ROWS, sizeof(int), 1, conn->file);
	if(rc != 1) die("Failed to write to database.", conn);
	int i = 0;
	for(; i < conn->db->MAX_ROWS; ++i) {
			rc = fwrite(
					&conn->db->rows[i]->id, 
					sizeof(int), 
					1, 
					conn->file
				);
			if(rc != 1) die("Failed to write to database.", conn);
			rc = fwrite(
					&conn->db->rows[i]->set, 
					sizeof(int), 
					1, 
					conn->file
				);
			if(rc != 1) die("Failed to write to database.", conn);
			if(conn->db->rows[i]->set) {
				rc = fwrite(
						conn->db->rows[i]->name, 
						sizeof(char)*MAX_DATA, 
						1, 
						conn->file
					);
				if(rc != 1) die("Failed to write to database.", conn);
				rc = fwrite(
						conn->db->rows[i]->email, 
						sizeof(char)*MAX_DATA, 
						1, 
						conn->file
					);
				if(rc != 1) die("Failed to write to database.", conn);
			}
	}

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush database", conn);
}

//initialize database with empty records
void
Database_create(struct Connection *conn)
{
	int i = 0;
	int MAX_ROWS = conn->db->MAX_ROWS;
	conn->db->rows = 
		(struct Address **) malloc(MAX_ROWS*sizeof(struct Address *));	

	for(i = 0; i < MAX_ROWS; i++) {

		struct Address *addr =
			(struct Address *) malloc(sizeof(struct Address));	
		addr->id = i;
		addr->set = 0;

		conn->db->rows[i] = addr;
	}
}
//set data on a database address
void
Database_set(struct Connection *conn, int id, 
				const char *name, const char *email)
{
	struct Address *addr = conn->db->rows[id]; //assign ref to addr pointer
	if(addr->set) die("Already set, delete it first", conn);

	addr->set = 1;
	//WARNING: bug, strncpy reads MAX_DATA bytes, if name is not null-term
	//neither is res
	addr->name = (char *) malloc(conn->db->MAX_DATA * sizeof(char));
	char *res = strncpy(addr->name, name, conn->db->MAX_DATA);

	if(!res) die("Name copy failed", conn);	

	addr->email = (char *) malloc(conn->db->MAX_DATA * sizeof(char));
	res = strncpy(addr->email, email, conn->db->MAX_DATA);
	if(!res) die("Email copy failed", conn);
}

//print a db address records
void
Database_get(struct Connection *conn, int id)
{
	struct Address *addr = conn->db->rows[id];

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
	conn->db->rows[id]->id = id;
	conn->db->rows[id]->set = 0;
	free(conn->db->rows[id]->name);
	free(conn->db->rows[id]->email);
}

//print contents of db
void
Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	for(i = 0; i < db->MAX_ROWS; i++) {
		struct Address *cur = db->rows[i];
	
		if(cur->set) {
			Address_print(cur);
		}
	}
}

void
Database_set_size(struct Connection *conn, int MAX_DATA, int MAX_ROWS)
{
	conn->db->MAX_DATA = MAX_DATA;
	conn->db->MAX_ROWS = MAX_ROWS;	
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

		Database_set_size(conn, MAX_DATA, MAX_ROWS);
	}
	int id = 0;

	if(argc > 3 && action != 'c') id = atoi(argv[3]);
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
			argv[4][name_sz] = '\0';
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd': //clear a rec by id, update file
			if(argc != 4) die("Need id to delete", conn);
			if(!conn->db->rows[id]->set) die("Record doesn't exist", conn);
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
