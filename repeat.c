#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "argstr.h"
#include "prtime.h"
#include "ttoms.h"

#define TRUE 1
#define FALSE 0

void help()
{
	printf("USAGE: repeat [option] command\n");
	printf("\t-d time[u,i,s,m,h] delay between commands (default=1s)\n");
	printf("\t-f keep running even command failed\n");
	printf("\t-n no delay between commands \n");
	printf("\t-t toggle time stamp (default on)\n");
	printf("\t[u,i,s,m,h] microsecond millisecond second minute hour\n");
}

#define DELAY_TIME 1000000 /* 1 second */
int delay = DELAY_TIME,
    force_run = FALSE,
    show_time = TRUE,
    keep_running = TRUE;

/* Signal handler */
void intHandler(int sig)
{
	keep_running = 0;
}

int handleArgument(int argc, char *argv[])
{
	int opt;
	while ((opt = getopt(argc, argv, "+d:fhnt")) != -1) {
		switch (opt) {
		case 'd':
			delay = ttous(optarg);
			break;
		case 'f':
			force_run = TRUE;
			break;
		case 'n':
			delay = FALSE;
			break;
		case 't':
			show_time = FALSE;
			break;
		case 'h':
		default:
			return 1;
		}
	}
	return 0;
}

#define ERR(i) \
	{help(); return i;}

int main(int argc, char *argv[])
{
	signal(SIGINT, intHandler);

	if (handleArgument(argc, argv))
		ERR(1)

	/* Must have command */
	if (argv[optind] == NULL)
		ERR(2)

	char *command = argstr(argc, argv, optind);

	while (keep_running) {
		if (show_time)
			printf("[\e[01;32m%s\e[1;0m]\n", my_time());

		/* system() return command's return value 
		 * if force_run flag is set, keep running 
		 * even command failed to run */
		if (system(command) > 0 && force_run == FALSE)
			break;

		usleep(delay);
	}
	return -1;
}
