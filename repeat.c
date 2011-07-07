#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "argstr.h"

#define DEF_DELAY_TIME 1000000

//note:funtion in another file could not get main file's datatype declaration
//optind reindex arg order

/*help message with exit value*/
void help_msg(int exval){
	printf ( "USAGE: repeat [option] command\n" );
	printf ( "\t-d [second] delay between commands (default=1)\n" );
	printf ( "\t-n no delay between commands \n" );
	printf ( "\t-t toggle time stamp (default on)\n" );
	exit (exval);
}

int main(int argc, char *argv[])
{
	/*handle options */
	if ( argc ==  1 ) 
		help_msg(1);
	int opt, delay=DEF_DELAY_TIME, sh_time_flag=1;
	while ( (opt=getopt(argc, argv, "d:hnt")) != -1 ) {
		switch (opt){
			case 'd':
				delay = atof(optarg)*1000000;
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
	char *arg2str = argstr(argc, argv, optind);
	time_t t;
	char t_str[32];
	/*run a command*/
	while (1){
		/*print time*/
		time(&t);
		struct tm *t_local= localtime(&t);
		strftime(t_str,32,"%T", t_local);
		if (sh_time_flag == 1)
			fprintf (stdout, "[\e[32;01m%s\e[1;0m]\n", t_str );
		else 
			printf ( "\n" );
		system(arg2str);
		usleep(delay);
	}
	/*properbly never run*/
	return 0;
}
