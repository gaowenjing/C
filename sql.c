#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <errno.h>
#include <string.h>
//#include "argstr.h"

#define DB "keyword.sqlite"

int callBack(void* argv, int colume, char** text, char** name)
{

	printf("colume = %i\n", colume);
	printf("text = %s\n", text[0]);
	printf("text = %s\n", text[1]);
	printf("name = %s\n", name[0]);
	printf("name = %s\n", name[1]);
	printf("--------------------\n");
	return 0;
}

int main(int argc, char *argv[])
{
	sqlite3 *db;
	if (sqlite3_open(DB, &db) != 0) {
		fprintf(stderr, "Open database %s error.\n", DB);
		return 1;
	}
	char *sql = "select * from gwj;";
	char *mess;
	sqlite3_exec(db, sql, callBack, NULL, &mess);
	if (mess != NULL)
		fprintf(stderr, "%s\n", mess);
	sqlite3_close(db);
	return 0;
}

