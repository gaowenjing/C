/*This program run a command after file is modified*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include "argstr.h"
#include "time.h"

#define INO_VERSION 1.0
/*select events to Monitor*/
//#define EVENTS IN_ALL_EVENTS
#define EVENTS IN_ACCESS|IN_ATTRIB|IN_MODIFY|IN_CLOSE|IN_MOVE|IN_OPEN

/*print help message and exit with a value*/
void help_msg(char *s, int exval){
	printf ( "USAGE: %s FILENAME COMMAND \n", s);
	exit(exval);
}
/*print the inotify events*/
void pr_event(unsigned int c){
	char *s;
	switch (c) {
		case IN_MODIFY:  s="modified";  break;
		case IN_ATTRIB:  s="attrib";    break;
		case IN_ACCESS:  s="access";    break;
		case IN_CLOSE: 	 s="close";     break;
		case IN_MOVE: 	 s="move";      break;
		case IN_OPEN: 	 s="open";      break;
		default: 	 s="other";
	}
	/*print time and event */
	printf ( "[\e[1;32m%s\e[1;0m] recieved %s event %u in %u\n", my_time(), s, c, IN_ALL_EVENTS );
}

int main(int argc, char *argv[])
{
	if (argc < 3 ) 
		help_msg(argv[0], 1);
	/*make arguemnt to command string for system()*/
	char *cmd = argstr(argc, argv, 2);
	/*inotify funtions start */
	int fd, wd;
	struct inotify_event e;
start:
	fd = inotify_init();
	if ((wd = inotify_add_watch(fd, argv[1], EVENTS)) == -1)
		error(1, 0, "inotify add watch error, %s exist?", argv[1]);
	read(fd, &e, sizeof(e));                /* read events */
	pr_event(e.mask);                       /* print events */
	inotify_rm_watch(fd, wd);               /* clean up */
	close(fd);
	/*inotify funtions end*/
	system(cmd);                            /* run command */
	goto start;                             /* restart Monitor */
	return 0;
}
