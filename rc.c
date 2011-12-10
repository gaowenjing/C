#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <error.h>
#include <errno.h>

#define CONF "gwj.d"

/*read config*/

int main(int argc, const char *argv[])
{
	FILE *fs = fopen(CONF, "r");
	if (fs == NULL)
		error(EXIT_FAILURE, errno, "%s", CONF);
	char left[20], right[20], tmp[1024];
	/*get configure file value*/
	int n;
	while ( (n = fscanf(fs, "%[^= \t\n]%[= \t\n]%[^\t\n]\n",
		 left, tmp, right)) > 0)        /* EOF = -1 */
	{
		printf("n = %d\n", n);
		printf ( "left = %s\t", left );
		printf ( "right = %s\t", right );
		printf ( "tmp = %s\n", tmp );
	}
	return 0;

}

