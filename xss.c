#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <X11/extensions/scrnsaver.h>
#include <string.h>
#include "ttoms.h"

#define IDLE_TIME 1800000
#define SLEEP_CMD "sudo pm-suspend"

 /* print help message and return exit value */
void helpmsg(int exval){
	printf ( "USAGE: xss [options] [time] \n" );
	printf ( "\t -r replace current running session \n" );
	printf ( "\t -c run another sleep command (default pm-suspend) (not finished)\n" );
	printf ( "\t -n daemon mode off (default on) \n" );
	printf ( "\t -s show idle time \n" );
	printf ( "\t -x killall xss process\n" );
	printf ( "\t default time format second ;could be h,m,s,i\n" );
	exit (exval);
}

int main(int argc, char *argv[])
{
	/*handle options*/
	int flag_exit = 0,
		flag_showtime = 0,
	   	flag_daemon = 1,
		flag_replace = 0; 

	char sleep_command[20] = SLEEP_CMD;

	/*circle get arguemnt*/
	int opt;
	while ( (opt = getopt(argc, argv, "c:hnrsx")) != -1) {
		switch (opt){
			case 'c':
				strcpy( sleep_command, optarg );
				break;
			case 'n':
				flag_daemon = 0;
				break;
			case 'h':
				helpmsg(0);
				break;
			case 'r':
				flag_replace = 1;
				break;
			case 's':
				flag_showtime = 1;
				break;
			case 'x':
				flag_exit = 1;
				break;
			case '?':
				helpmsg(1);
		}
	}

	/*handle the -x flag*/
	if ( flag_exit == 1)
		system("pkill -x xss");

	/*check if another session is running*/
	char check_process_command[32];
	sprintf (check_process_command, "pgrep -xo xss | grep -qov %i", getpid()); 
	if (system(check_process_command) == 0 )    /* 0: exist */
	{
			if (flag_replace == 0)              /* 0: not replace */
					error(1, 0, "another session is running");
			else 
					system("pkill -xo xss");
	}

	/*define idle time to suspend*/
	unsigned int idle_time;
	if ( argv[optind] == NULL ) 
		idle_time = IDLE_TIME;
	else if ((idle_time = ttoms(argv[optind])) == 0 )
			error(1, 0, "error time format");
	printf ( "sleep after idle for %u second\n",idle_time/1000 );

	/*fork program*/
	if (flag_daemon == 1){
		pid_t pid = fork();
		/*exit main process leave fork process*/
		if ( pid < 0 )
			error(1, 0, "error on fork");
		else if ( pid > 0 )             /* parent exit */
			exit (0);
	}

	/*open Display*/
	XScreenSaverInfo *info = XScreenSaverAllocInfo();
	Display *dis = XOpenDisplay(NULL) ;
	if ( dis == NULL ) {
		error (1,0,"Error opening Display") ; 
	}

	/*get idle time and run suspend program*/
	while(1) {
		XScreenSaverQueryInfo( dis, DefaultRootWindow(dis), info);
		/*whether print idle time */
		if (flag_showtime == 1)
			printf ( "idle for %lu second\n", info->idle/1000 );
		/*condition compartion*/
		if ( info->idle > idle_time ) {
			/*run sleep command here*/
			if (system(sleep_command) == -1 ) 
			       error(1,0,"sleep command error");
		}
	sleep(3);
	}
	XCloseDisplay(dis);
	return 0;
}
