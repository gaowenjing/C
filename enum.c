#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char *argv[])
{
	enum keywords
	{
		a, b, c, d, e, f, g
	};
	enum keywords kw = f;
	printf ( "%u\n", kw );
	return 0;
}
