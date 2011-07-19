#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<errno.h>

/*read config*/

int main(int argc, const char *argv[])
{
	FILE *fs = fopen(argv[1], "r");
	if (fs == NULL)
		return errno;
	char left[20], right[20];
//	fgets(s, 1024, fs);
//	printf ( "%s", s );
//	fgets(s, 1024, fs);
//	printf ( "%s", s );
	while ( fscanf ( fs, "%s = %s", left, right ) != EOF )
	{
		printf ( "left = %s\n", left );
		printf ( "right = %s\n", right );
	}
	return 0;
}

