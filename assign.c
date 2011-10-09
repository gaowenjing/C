#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

#define xxx 1

/*note: In function pointer is changed*/
void assign( char x )
{
	printf ( "in-func(1) %p\n", &x );
	x = 'X';
	printf ( "in-func(1) %p\n", &x );
}

void assign2( char *x )
{
	*x = 'X';
	printf ( "in-func(2) %p\n", x );
	printf ( "in-func(2) %s\n", x );
}
int main(int argc, const char *argv[])
{
	struct gwj {
		int a;
		char *b;
		char c;
	};
//	struct gwj x = {
//		.a=3,
//		.b="sfjdls",
//		.c='2',
//	};
//	char *t;
//	char *s;
//	printf ( "%s,%s\n", s, t );
//	printf ( "%p,%p\n", s, t );
//	char a='b';
//	printf ( "%p,%c\n", &a, a );
//	a='c';
//	printf ( "%p,%c\n", &a, a );
	char a='b';
	printf ( "orignal %p\n", &a );
	assign(a);
	printf ( "after assign: %c\n", a );
	printf ( "after assign: %p\n", &a );
	assign2(&a);
	printf ( "after assign2: %p\n", &a );
	printf ( "after assign2: %c\n", a );
	return 0;
}

