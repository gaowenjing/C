#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <error.h>
//#include <err.h>
//#include <errno.h>

/*simple function like cat */

int main(int argc, const char *argv[])
{
	int fd=open(argv[1],O_RDONLY);
	if (fd == -1)
//		err(errno,"fd");
		perror("fd");
	char *buf=malloc(1000);
	while (read(fd,buf,1000 > 0)){
		printf ( "%s",buf );
	}
	free(buf);
	return 0;
}
