#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "argstr.h"
#include "prtime.h"
#include "ttoms.h"

#define DEF_DELAY_TIME 1000000

//note:funtion in another file could not get main file's datatype declaration

/*help message with exit value*/
void help_msg(int exval){
	printf ( "USAGE: repeat [option] command\n" );
	printf ( "\t-d time[u,i,s,m,h] delay between commands (default=1s)\n" );
	printf ( "\t-n no delay between commands \n" );
	printf ( "\t-t toggle time stamp (default on)\n" );
	printf ( "\t[u,i,s,m,h] microsecond millisecond second minute hour\n" );
	exit (exval);
}

int main(int argc, char *argv[])
{
	/*handle options */
	if ( argc ==  1 ) 
		help_msg(1);
	/*initial options*/
	int opt, delay=DEF_DELAY_TIME, sh_time_flag=1;
	while ( (opt=getopt(argc, argv, "+d:hnt")) != -1 ) {
		switch (opt){
			case 'd':
				delay = ttous(optarg);
				break;
			case 'h':
				help_msg(0);
				break;
			case 'n':
				delay = 0;
				break;
			case 't':
				sh_time_flag=0;
				break;
		}
	}
	/*make argv to string for command*/
	if (argv[optind] == NULL ) 
		help_msg(2);
	char *args = argstr(argc, argv, optind);
	/*run a command*/
	while (1){
		/*print time*/
		if (sh_time_flag == 1)
			pr_time();
		else 
			printf ( "\n" );
		if (system(args) > 1)
			break;
		usleep(delay);
	}
	/*properbly never run*/
	return -1;
}
