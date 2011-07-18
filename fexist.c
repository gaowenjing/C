#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<fcntl.h>

#define READ_FILE 

int main(int argc, const char *argv[])
{
	int fd;
	if ( ( fd = open(argv[1], O_RDONLY ) ) == -1 )
		perror("fd");	
	return 0;
}

