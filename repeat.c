#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "argstr.h"
#include "prtime.h"
#include "ttoms.h"

#define DELAY_TIME 1000000
#define TRUE 1
#define FALSE 0

/* help message with exit value */
void help()
{
	printf("USAGE: repeat [option] command\n");
	printf("\t-d time[u,i,s,m,h] delay between commands (default=1s)\n");
	printf("\t-f keep running even command failed\n");
	printf("\t-n no delay between commands \n");
	printf("\t-t toggle time stamp (default on)\n");
	printf("\t[u,i,s,m,h] microsecond millisecond second minute hour\n");
}

int keep_running = 1;
void intHandler(int sig)
{
	keep_running = 0;
}

int main(int argc, char *argv[])
{
	if (argc < 1) {
		help();
		return 1;
	}
	signal(SIGINT, intHandler);
	int opt, delay = DELAY_TIME, force_run = FALSE, show_time = TRUE;

	while ((opt = getopt(argc, argv, "+d:fhnt")) != -1) {
		switch (opt) {
		case 'd':
			delay = ttous(optarg);
			break;
		case 'f':
			force_run = TRUE;
			break;
		case 'h':
			help();
			break;
		case 'n':
			delay = FALSE;
			break;
		case 't':
			show_time = FALSE;
			break;
		}
	}

	if (argv[optind] == NULL) {
		help();
		return 2;
	}

	char *command = argstr(argc, argv, optind);

	while (keep_running) {
		if (show_time == TRUE)
			printf("[\e[01;32m%s\e[1;0m]\n", my_time());
		else
			printf("\n");

		if (system(command) > 1 && force_run == FALSE)
			break;
		usleep(delay);
	}
	return -1;
}
