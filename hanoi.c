#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>


//void hanoi(int floor, char *x) {
//	if (floor > 1)
//		hanoi(--floor);
//	printf ( "%c\n", a );	
//	a=b;
//}

int main(int argc, const char *argv[])
{
	//	hanoi(10);	
	char a='A', b='B';
	char c=a;
	//	printf ( "%c,%c,%c\n", a, b, c );
	printf ( "%p,%p,%c\n", &a, &b, c );
	printf ( "%p,%p,%c\n", &a, &b, c );
	printf ( "%c,%c,%c\n", a, b, c );
	return 0;
}

