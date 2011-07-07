#include <string.h>
#include <stdio.h>

/*test the function err and strerror , output their normal error message*/
int main(int argc, const char *argv[])
{
	
	int i;
	for (i = 0; i < 133; i++) {
		printf ( "%i: %s\n", i, strerror(i) );
	}
	return 0;
}
