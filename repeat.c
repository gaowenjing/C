#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "argstr.h"
#include "prtime.h"
#include "ttoms.h"

#define DELAY_TIME 1000000
#define YES 1
#define NO 0

/*help message with exit value*/
void help(int exval)
{
	printf ( "USAGE: repeat [option] command\n" );
	printf ( "\t-d time[u,i,s,m,h] delay between commands (default=1s)\n" );
	printf ( "\t-f keep running even command failed\n" );
	printf ( "\t-n no delay between commands \n" );
	printf ( "\t-t toggle time stamp (default on)\n" );
	printf ( "\t[u,i,s,m,h] microsecond millisecond second minute hour\n" );
	exit (exval);
}

int main(int argc, char *argv[])
{
	if ( argc <  1 ) 
		help(1);
	int opt, 		/* handling arguments */
	    delay 		= DELAY_TIME,
	    force_run 		= NO,
	    sh_time_flag 	= YES;
	while ( (opt = getopt(argc, argv, "+d:fhnt")) != -1 )
	{
		switch (opt)
		{
			case 'd':
				delay = ttous(optarg);
				break;
			case 'f':
				force_run = YES;
				break;
			case 'h':
				help(0);
				break;
			case 'n':
				delay = NO;
				break;
			case 't':
				sh_time_flag = NO;
				break;
		}
	}

	if (argv[optind] == NULL) 
		help(2);
	char *command = argstr(argc, argv, optind);

	while (YES)
	{
		if (sh_time_flag == YES)
			pr_time(); 		/*print time*/
		else 
			printf ("\n");          /* divide two result */
		if (system(command) > 1 && force_run == NO)
			break;
		usleep(delay);
	}
	return -1;
}
