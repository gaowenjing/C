#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "argstr.h"
#include <string.h>
#include <error.h>

int main(int argc, char *argv[])
{
	/*pointer test*/
	char *s=malloc(0);
	char *t=malloc(1);
	s[0]='c';
	s=realloc(s, 25);
	char *u=malloc(0);
	char v[24];
	char w[17];
//	w[0]='z';
//	s[0]='a';
//	s[1]='b';
//	s[2]='c';
	printf ( "%s\n", s );
	printf ( "%p\n", s );
	printf ( "%p\n", t );
	printf ( "%p\n", u );
	printf ( "%s\n", u );
	printf ( "%p\n", v );
	printf ( "%p\n", w );
	printf ( "%s\n", v );
	printf ( "%s\n", w );
	free(s);
	free(t);
	return 0;
}
