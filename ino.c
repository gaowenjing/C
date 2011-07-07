#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include "argstr.h"

//#define EVENTS IN_ALL_EVENTS
#define EVENTS IN_MODIFY|IN_ATTRIB

/*This function run a command after file is modified*/

void pr_event(unsigned int c){
	switch (c) {
		case IN_MODIFY:
			printf ( "event:modify\n" );
			break;
		case IN_ATTRIB:
			printf ( "event:attrib\n" );
			break;
		default:
			printf ( "other event\n" );
	}
}
int main(int argc, char *argv[])
{
	if (argc < 2 ) 
		error(1, 0, "USAGE: %s [filename] [command]", argv[0]);
	//argv to string for system()
	char *cmd = argstr(argc, argv, 2);
	//inotify_add_watch
	int fd, wd;
	struct inotify_event e;
start:
	fd = inotify_init();
	wd = inotify_add_watch(fd, argv[1], EVENTS);
	if (wd == -1)
		error(1, 0, "inotify add watch error");
	// file event
	read(fd, &e, sizeof(e));
	pr_event(e.mask);
	//inotify_rm_watch
	inotify_rm_watch(fd, wd);
	//run a command 
	system(cmd);
	close(fd);
	//restart monitor
	goto start;
	free(str);
	return 0;
}
