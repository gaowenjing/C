#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<signal.h>
#include 	"xke.h"

short excode = 1;

void loop(void)
{
	int i=0;
	while (excode){
		printf ( "%i\n", i );
		sleep(1);
		i++;
	}
}

int main(int argc, const char *argv[])
{
//	int excode=1;
//	pid_t pid = fork();
//	if (pid > 0){
//		while (excode){
//			printf ( "Yello fork pid is %u.\n", getpid() );
//			sleep(1);
//		}
//	}
//	if (pid == 0){
//		if (xke()==0)
//			kill(pid, SIGQUIT);
//		else 
//			printf ( "can not connect X.\n" );
//	}
	int pid = fork();
	switch (pid) {
		case -1 :
			printf ( "fork failed \n" );
			return -1;
		case 0 :                 /* child */
			loop();
			break;
		default:                        /* parent */
			if (xke() == 0)
				/*useless course they are in different process*/
				excode = 0;
	}
	return 0;
}

