#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*keywords that deleting from history*/
#define KEYWORDS { \
	"fuck", "renti", "rtys", "yishu", "xvideo", "人体", \
	"pussy", "japanese", "porn", "大胆", "人體", "亚洲色", \
	"色色", "女优" \
}

int verbose_flag = 0;

char *parseDatabasePath(void)
{
	return NULL;
}

/*delete from database*/
void privacy(char *keyword, sqlite3 * db)
{
	char *sql = malloc(1024);
	char *mess = malloc(1024);
	sprintf(sql,
		"DELETE FROM moz_places where url like '%%%s%%' or title like '%%%s%%';",
		keyword, keyword);
	if (verbose_flag == 1)
		printf("%s\n", sql);
	sqlite3_exec(db, sql, NULL, NULL, &mess);
	if (mess != NULL)
		printf("%s\n", mess);
	free(sql);
	free(mess);
}

char *keywords[] = KEYWORDS;

int main(int argc, char *argv[])
{
	/*Get options */
	int opt;
	while ((opt = getopt(argc, argv, "+hv")) != -1) {
		switch (opt) {
		case 'v':
			verbose_flag = 1;
			break;
		case 'h':
			fprintf(stdout, "Usage: %s [-v]", argv[0]);
			exit(EXIT_SUCCESS);
			break;
		default:
			fprintf(stderr, "Usage: %s [-v]", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	/*open database */
	sqlite3 *db;
	if (sqlite3_open
	    ("/home/gwj/.mozilla/firefox/bul0h084.default/places.sqlite",
	     &db) != 0) {
		fprintf(stderr, "Open database error\n");
		return -1;
	}

	/*execute sql */
	int i;
	for (i = 0; i < sizeof(keywords) / sizeof(*keywords); i++)
		privacy(keywords[i], db);
	sqlite3_close(db);
	return 0;
}
