#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "argstr.h"
#include "time.h"
#include <string.h>
#include <error.h>

int main(int argc, char *argv[])
{
	typedef struct gwj{
		int a;
		char *b;
		float c;
	} g;
	/*pointer test*/
//	g *x;
//	printf ( "%p\n", &x );
//	printf ( "%p\n", &x->a );
//	printf ( "%p\n", &x->b );
//	printf ( "%p\n", &x->c );
//	getchar();
	while (1){
		char c=fgetc(stdin);
		if ( c == 'q')
			break;
//		putchar(c);
	}
	return 0;
}
