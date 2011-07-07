#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<error.h>
#include 	<dirent.h>
#include 	<err.h>
#include 	<errno.h>

int main(int argc, const char *argv[])
{
	/*fopen and fread*/
//	FILE *stream;
//	char *ptr=malloc(1000);
//	if ((stream = fopen(argv[1], "rw")) == NULL)
//		error(1, 0, "fopen failed");
//	while (fread(ptr, 1, 1000, stream ) > 0) 
//		printf ( "%s\n", ptr );
//	free(ptr);

	/*diropen and readdir*/
	DIR *od;
	if ((od=opendir("/usr")) == NULL )
		err(errno, "opendir");
	struct dirent *de = readdir(od);	
	printf ( "%lu\n", de->d_ino);
	closedir(od);
	return 0;
}

