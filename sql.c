#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <errno.h>
#include <string.h>

/*test sqlite3 function*/

/*error function*/
void err(int exval, const char *fmt) {
	printf ( "%s\n", fmt );
	exit (exval);
}

int main(int argc, const char *argv[])
{
	sqlite3 *db;
	if (sqlite3_open(argv[1], &db) !=0 )
		err(errno, "open database error");
	/*create table gwj*/
	/*redicioulars prepare/step/finalize 3 step */
//	char *zsql= "create table gwj(text, priority INTERGER)";
//	sqlite3_stmt *gwj_c;
//	sqlite3_prepare_v2(db, zsql, -1, &gwj_c, NULL);
//	if (sqlite3_step(gwj_c) != 101){
//		/*err(errno, "sqlite3_step error");*/
//		/*drop table gwj*/
//		char *zsql_drop = "drop table gwj";
//		sqlite3_prepare_v2(db, zsql_drop, -1, &gwj_c, NULL);
//		sqlite3_step(gwj_c);
//	}
	sqlite3_exec(db, "create table gwj(test, priority INTERGER)", )
	sqlite3_close(db);
	return 0;
}


