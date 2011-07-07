#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	int i;
	srand(time(0));
	for (i = 0; i < 10000; i++) {
		printf ( "%i\n", rand() );	/* code */
	}
	return 0;
}
