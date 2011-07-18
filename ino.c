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
#include "prtime.h"

#define INO_VERSION 1.0
/*select events to Monitor*/
#define EVENTS IN_ALL_EVENTS
//#define EVENTS IN_ACCESS|IN_ATTRIB|IN_MODIFY|IN_CLOSE|IN_MOVE|IN_OPEN

#define DEBUG_FLAG 1

/*print help message and exit with a value*/
void help_msg(char *s, int exval){
	printf ( "USAGE: %s FILENAME COMMAND \n", s);
	exit(exval);
}
/*print the inotify events*/
void pr_event(uint32_t emask, char *filename, uint32_t len, char *path){
	char *s=NULL;
	switch (emask) {
		case IN_MODIFY:  s="modified"; break;
		case IN_ATTRIB:  s="attrib";    break;
		case IN_ACCESS:  s="access";    break;
		case IN_CLOSE: 	 s="close";     break;
		case IN_MOVE: 	 s="move";      break;
		case IN_OPEN: 	 s="open";      break;
		default: 	 s="other";
	}
	/*print time and event */
	if (len == 0 )
		filename=path;
	printf ( "[\e[1;32m%s\e[1;0m] Received \e[1;31m%s(%u)\e[0m from \e[1;33m%s\e[0m\n", my_time(), s, emask, filename);
}

int main(int argc, char *argv[])
{
	if (argc < 2 ) 
		help_msg(argv[0], 1);
	/*make arguemnt to command string for system()*/
	char *cmd=NULL;
	if (argv[2])
		cmd = argstr(argc, argv, 2);
	/*inotify funtions start */
	int fd, wd;
	struct inotify_event e;
start:
	fd = inotify_init();
	if ((wd = inotify_add_watch(fd, argv[1], EVENTS )) == -1)
		error(1, 0, "Inotify add watch error, %s exist?", argv[1]);
	ssize_t bs = read(fd, &e, sizeof(e)+256);                /* read events */
	printf ( "ssize_t read = %lu\n", bs );
	pr_event(e.mask, e.name, e.len, argv[1]);   /* print events */
	inotify_rm_watch(fd, wd);               /* clean up */
	close(fd);
	/*inotify funtions ends and run a command*/
	if (cmd && open(argv[2], O_RDONLY) != -1) 
		system(cmd);                    
	else
		printf ( "error running cmd\n" );
	goto start;                             /* restart Monitor */
	return 0;
}
