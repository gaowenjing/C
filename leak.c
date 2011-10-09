#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

int main(int argc, const char *argv[])
{
	char *a=malloc(1);
	printf ( "%p\n", a );
	unsigned long long i=1;
	while(1)
	{
		a = realloc (a, i);
		printf ( "%p\n", a );
		i+=10000000000;
		printf ( "%p\n", a );
		usleep(1000000);
	}
	return 0;
}

