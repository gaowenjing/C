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
#include <string.h>

#define EVENTS IN_CLOSE_WRITE|IN_ONESHOT

#define MAXBUF 256
#define CMDFILE "cmd"
char *parseCmd(void)
{
	FILE *fs = fopen(CMDFILE, "r");
	if (fs == NULL) {
		fprintf(stderr, "Open %s Error\n", CMDFILE);
		exit(EXIT_FAILURE);
	}
	char buf[MAXBUF];
	char *str = malloc(1024);
	while (fgets(buf, MAXBUF, fs) != NULL) {
		strncat(str, buf, strlen(buf) - 1);
		strcat(str, " ; ");
	}
	return str;
}

/*print the inotify events*/
void printEvent(struct inotify_event *event)
{
	printf("[\e[1;32m%s\e[1;0m] EVENTS: ", my_time());

	if (event->mask & IN_MODIFY)
		printf("modified ");
	if (event->mask & IN_ATTRIB)
		printf("attrib ");
	if (event->mask & IN_ACCESS)
		printf("access ");
//      if (event->mask & IN_CLOSE)     printf("close ");
	if (event->mask & IN_MOVE)
		printf("move ");
	if (event->mask & IN_OPEN)
		printf("open ");
	if (event->mask & IN_ISDIR)
		printf("isdir ");
	if (event->mask & IN_ONESHOT)
		printf("oneshot ");
	if (event->mask & IN_DELETE)
		printf("delete ");
	if (event->mask & IN_DELETE_SELF)
		printf("delete_self ");
	if (event->mask & IN_MOVE_SELF)
		printf("move_self ");
	if (event->mask & IN_CLOSE_WRITE)
		printf("close_write ");
	if (event->mask & IN_CLOSE_NOWRITE)
		printf("close_nowrite ");
	if (event->mask & IN_CREATE)
		printf("create ");

	if (event->len)
		printf("FILE: \e[1;33m%s\e[0m", event->name);
	printf("\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s FILENAME [COMMAND]\n", argv[0]);
		return EXIT_FAILURE;
	}

	/*make arguemnt to command string for system() */
	char *cmd = NULL;
	if (argv[2])
		cmd = argstr(argc, argv, 2);
	else
		cmd = parseCmd();

	/*inotify funtions start */
	int fd, wd;
	struct inotify_event event;
 start:
	fd = inotify_init();
	if ((wd = inotify_add_watch(fd, argv[1], EVENTS)) == -1)
		error(1, 0, "Inotify add watch error, %s exist?", argv[1]);
	read(fd, &event, sizeof(event) + MAXBUF);
	printEvent(&event);
	inotify_rm_watch(fd, wd);	/* clean up */
	close(fd);

	/*inotify funtions ends and run a command */
	if (cmd) {
		system(cmd);
	}
	goto start;		/* restart Monitor */
	return 0;
}
