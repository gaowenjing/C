#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

#define SHELL "/bin/sh"

int main(int argc, const char *argv[])
{
	execl(SHELL, SHELL, "-c", "killall", argv[1], NULL);
	sleep(10);
	return 0;
}

