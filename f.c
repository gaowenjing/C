#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

int main(int argc, const char *argv[])
{
	int i;
	for (i = 0; i < 1000; i++) {
		pid_t pid = fork();
		if (pid == 0)
			system("repeat -n curl -s 'http://gwj.local/cgi-bin/c' > /dev/null");
	}
	return 0;
}

