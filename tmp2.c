#include 	<stdio.h>
#include 	<stdlib.h>

int a=1;

void as (int a)
{
	printf ( "in-func(as):%p\n", &a );
	a=2;
	printf ( "in-func(as):%p\n", &a );
}

int main(int argc, const char *argv[])
{
	int a=0;
	printf ( "in-main: %p\n", &a );
	as(a);
	printf ( "in-main: %p\n", &a );
	printf ( "in-main: %i\n", a );
	return 0;
}
