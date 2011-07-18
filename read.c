#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*simple function like cat */

int main(int argc, const char *argv[])
{
	int fd=open(argv[1],O_RDONLY);
	if (fd == -1)
		perror("fd");
	char *buf=malloc(100);
	while (read(fd,buf,100 > 0)){
		printf ( "%s",buf );
	}
	free(buf);
	return 0;
}
