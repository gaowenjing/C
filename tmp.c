#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "argstr.h"
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
	/*int i=0;*/
	/*char s[20];*/
	/*s[i] = 'c';*/
	/*[>s[i++] = 'd';<]*/
	/*[>printf ( "%i\n", i );<]*/
	/*s[++i] = 'e';*/
	/*s[20] = '\0';*/
	/*printf ( "%s\n", s );*/
	char *s=malloc(0);
	char *t=malloc(1);
	s[0]='c';
	s=realloc(s, 25);
	char *u=malloc(0);
	char v[24];
	char w[17];
	w[0]='z';
	/*s[0]='a';*/
	/*s[1]='b';*/
	/*s[2]='c';*/
	/*int i;*/
	/*for (i = 0; i < 90; i++) {*/
		/*s[i]='a';*/
	/*}*/
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
	return 0;
}
