#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

/*NULL pointer is nil*/
int main(int argc, const char *argv[])
{
	char *s=NULL;
	printf ( "%p\n", s );
	printf ( "%s\n", s );
	printf ( "%p\n", &s );
	return 0;
}

