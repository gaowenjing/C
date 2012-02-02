#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include "argstr.h"
#include "prtime.h"
#include <string.h>
#include <signal.h>

#define EVENTS IN_CLOSE_WRITE

#define ERROR(str, i) \
	{ perror(str); exit(i); }

/* This program run a command after file is modified */
#define MAXBUF 256
#define CMDFILE "cmd"
/* Read command from a file */
char *parseCmd(void)
{
	FILE *fs = fopen(CMDFILE, "r");
	if (fs == NULL)
		ERROR("fopen", 1)

	char buf[MAXBUF];
	char *str = malloc(MAXBUF);
	while (fgets(buf, MAXBUF, fs) != NULL) {
		strncat(str, buf, strlen(buf) - 1);
		strcat(str, " ; ");
	}
	return str;
}

/*print the inotify events*/

int keep_running = 1;
void intHandler(int sig)
{
	fprintf(stderr, "received interrupt.\n");
	keep_running = 0;
}

int inotify(char *filename)
{
	struct inotify_event event;
	int fd = inotify_init();
	int wd = inotify_add_watch(fd, filename, EVENTS);
	if (wd == -1)
		ERROR("Add watch error", 1)
	read(fd, &event, sizeof(event) + MAXBUF);

	printf("[\e[1;32m%s\e[1;0m]\n", my_time());

	inotify_rm_watch(fd, wd);
	close(fd);
	return 8;
}

int main(int argc, char *argv[])
{
	signal(SIGTERM, intHandler);
	signal(SIGINT, intHandler);

	if (argc < 2) {
		fprintf(stderr,
			"Usage: %s FILENAME [COMMAND]\n", argv[0]);
		return EXIT_FAILURE;
	}

	/*make argument to command string for system() */
	char *cmd = NULL;
	if (argv[2])
		cmd = argstr(argc, argv, 2);
	else
		cmd = parseCmd();

	/*inotify function start */

	while (keep_running) {
		inotify(argv[1]);
	
		/*run a command */
		if (cmd) 
			system(cmd);
	}	
	return 5;
}
