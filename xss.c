#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <X11/extensions/scrnsaver.h>
#include <string.h>
#include "ttoms.h"

#define IDLE_TIME 1800000
#define SLEEP_CMD "sudo pm-suspend"


int main(int argc, char *argv[])
{
	//define idle time to suspend
	unsigned int idle_time;
	if ( argv[1] == NULL ) 
		idle_time = IDLE_TIME;
	else
		idle_time = ttoms(argv[1]);
	printf ( "sleep after idle for %u\n",idle_time );
	//open Display
	XScreenSaverInfo *info = XScreenSaverAllocInfo();
	Display *dis = XOpenDisplay(NULL) ;
	if ( dis == NULL ) {
		error (1,0,"Error opening Display") ; 
	}
	//get idle time and run suspend program
	while(dis) {
		XScreenSaverQueryInfo( dis, DefaultRootWindow(dis), info);
		if ( info->idle > idle_time ) {
			system("notify-send 'system is going to sleep in 10 second'");
			sleep(10);
			if (system(SLEEP_CMD) == -1 ) 
			       error(1,0,"SLEEP_CMD error");
		}
	sleep(1);
	}
	XCloseDisplay(dis);
	return 0;
}
