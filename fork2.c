#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<signal.h>
#include 	<sys/wait.h>

/*note: global declaration so every function could use it*/
int exval = 1;

/*when fork pid 0 is child , pid > 0 is parent*/
void child_watch(int something)
{
	printf ( "This is a function\n" );
	printf ( "something = %i\n", something );
	exval = 0;
}

int main(int argc, const char *argv[])
{
	signal (SIGCHLD, child_watch);
//	printf ( "parent = %i\n", getpid() );
	pid_t p =  fork();
	switch ( p ) {
		case -1:                        /* fork error */
			printf ( "failed fork\n" );
			return -1;
		case 0:                         /* child */
//			printf ( "0 = %i\n", getpid() );
			sleep(3);
			exit (1);
		default:                        /* parent */
			while (exval){
				printf ( "looping...\n" );
				sleep(1);
			}
	}
	printf ( "End of function\n" );
	return 0;
}

