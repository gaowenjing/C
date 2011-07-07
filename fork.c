#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<signal.h>
#include 	"xke.h"

int main(int argc, const char *argv[])
{
	int excode=1;
	pid_t pid = fork();
	if (pid > 0){
		while (excode){
			printf ( "Yello fork pid is %u.\n", getpid() );
			sleep(1);
		}
	}
	if (pid == 0){
		if (xke()==0)
			kill(pid, SIGQUIT);
		else 
			printf ( "can not connect X.\n" );
	}
	return 0;
}

