#include 	<stdio.h>
#include 	"ip2int.h"

int main(int argc, char *argv[])
{
	if (argv[1] == NULL)
		return -1;
	unsigned int ip = ip2int(argv[1]);
	if (ip == -1)
		fprintf ( stderr, "Wrong IP.\n" );
	else
		printf ( "%u\n", ip );
	return 0;
}

