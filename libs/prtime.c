#include <stdio.h>
#include <time.h>

/*print time directly*/
void pr_time(void){
	time_t t = time(NULL);
	static char s[10];
	struct tm *lt = localtime(&t);
	if (strftime(s, 10, "%T", lt) == 0)
		fprintf ( stderr, "strftime error\n" );
	/*why there's no output?*/
	/*note: need \n to printf out*/
	fprintf ( stdout, "[\e[01;32m%s\e[0m\e[1m]\n",s );
}

/*return time */
char *my_time(void){
	time_t t = time(NULL);
	static char my_time[20];
	/*printf ( "%p\n",my_time );*/          /* same pointer */
	if (strftime(my_time, 10, "%T", localtime(&t)) == 0)
	       fprintf (stderr, "strftime error\n");
	return my_time;
}
