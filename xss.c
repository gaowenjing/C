#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/extensions/scrnsaver.h>
#include <string.h>
#include "ttoms.h"
#include <signal.h>
#include <dirent.h>

#define ERROR(str, i) \
	{ fprintf(stderr, str); return i; }

void helpmsg(void)
{
	printf("USAGE: xss [options] [time][h,m,s,i]\n");
	printf("\t -r replace current running session\n");
//	printf ("\t -c specify sleep cmd (default pm-suspend)\n");
	printf("\t -n daemon mode off (default on) \n");
	printf("\t -s show idle time\n");
	printf("\t -x kill all xss process\n");
	printf("\t default time format second [h,m,s,i]\n");
}

/* Default Options */
#define SLEEP_CMD "sudo pm-suspend"
char sleep_command[20] = SLEEP_CMD;

#define IDLE_TIME "30m" /* Default idle time 30 minute */

#define TRUE 1
#define FALSE 0

#define KILL 0
#define SHOWTIME 1
#define DAEMON 2
#define REPLACE 3
#define KEEP_RUNNING 4
int flags[] = {
	[KILL] 		= FALSE,
	[SHOWTIME] 	= FALSE,
	[DAEMON] 	= TRUE,
	[REPLACE] 	= FALSE,
	[KEEP_RUNNING] 	= TRUE,
};

#define PIDFILE "/tmp/xss.pid"

int create_pid_file(void)
{
	FILE *fs = fopen(PIDFILE, "w");
	if (fs) {
		fprintf(fs, "%i\n", getpid());
		fclose(fs);
	} else {
		ERROR("Error on creating pid file .\n", 0);
	}

	return 1;
}

/* Return the pid value */
char *read_pid_string(void)
{
	FILE *fs = fopen(PIDFILE, "r");
	if (fs) {
		static char s[8];
//		fgets(s, 8, fs);
		fscanf(fs, "%s\n", s);
		return s;
	} else {
		return "0";
	}
}

/* The scandir filter */
char *exist_pid;
int thefilter(const struct dirent *p)
{
	if (strcmp(p->d_name, exist_pid) == 0)
		return 1;
	return 0;
}

int checkRunning(void)
{
	struct dirent **namelist;
	int n = scandir("/proc", &namelist, thefilter, alphasort);
	if (n > 0) {
		return 1;
	}
	else
		return 0;
}

void handleArguemnt(int argc, char *argv[])
{
	int opt;
	while ((opt = getopt(argc, argv, "c:hnrsx")) != -1) {
		switch (opt) {
		case 'c':
			strcpy(sleep_command, optarg);
			break;
		case 'n':
			flags[DAEMON] = FALSE;
			break;
		case 'h':
			helpmsg();
			exit(EXIT_SUCCESS);
		case 'r':
			flags[REPLACE] = TRUE;
			break;
		case 's':
			flags[SHOWTIME] = TRUE;
			break;
		case 'x':
			flags[KILL] = TRUE;
			break;
		case '?':
			helpmsg();
			exit(EXIT_FAILURE);
		}
	}
}

void intHandler(int sig)
{
	flags[KEEP_RUNNING] = 0;
}

int kill_exist_process(void)
{
	return kill(atoi(read_pid_string()), SIGINT);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, intHandler);
	signal(SIGTERM, intHandler);

	handleArguemnt(argc, argv);
	
	exist_pid = read_pid_string();

	/* Handle the -x (exit) flag */
	if (flags[KILL] == TRUE) 
		return kill_exist_process();

	/* Check if another session is running */
	if (checkRunning() == 1) {
		if (flags[REPLACE] == FALSE)
			ERROR("Another session is running.\n", 10)
		else
			kill_exist_process();
	}

	/* Define idle time to suspend */
	unsigned int idle_time;
	if (argv[optind] == NULL)
		idle_time = ttoms(IDLE_TIME);
	else
		idle_time = ttoms(argv[optind]);

	if (idle_time == 0)
		ERROR("Error time format.\n", FALSE)

	printf("Sleep after idle for %u seconds\n", idle_time/1000);

	/* Make process as a daemon */
	if (flags[DAEMON] == TRUE) {
		pid_t pid = fork();

		if (pid < 0)
			ERROR("Error on fork\n", FALSE)
		else if (pid > 0)
			return TRUE;
	}

	/* Store a pid file to /tmp/xss.pid */
//	create_pid_file();
	if (create_pid_file() == 0)
		ERROR("Error on creating pid file\n", 10)

	/* Open Display */
	XScreenSaverInfo *info = XScreenSaverAllocInfo();
	Display *display = XOpenDisplay(NULL);

	if (display == NULL)
		ERROR("Error openning Display.\n", FALSE)

	/* Get idle time and run suspend program */
	while (flags[KEEP_RUNNING]) {
		XScreenSaverQueryInfo(display,
				DefaultRootWindow(display), info);

		/* Whether print idle time */
		if (flags[SHOWTIME] == TRUE)
			printf(
			"Idle for %lu seconds.\n", info->idle/1000);

		/* Idle is in millisecond (second*1000) */
		if (info->idle > idle_time) {

			/* Run sleep command here */
			if (system(sleep_command) == -1)
				ERROR("Error on trying to sleep.\n", FALSE)
		}
		sleep(3);
	}
	XCloseDisplay(display);
	return 10;
}
