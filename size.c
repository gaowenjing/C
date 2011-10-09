#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

/*sizeof pointer is 8 bit , I should use strlen*/

int main(int argc, const char *argv[])
{
//	struct apple {
//		int num;
//		char *taste;
//		char *color;
//		char *com;
//	} apple;
//	printf ( "%p\n", &apple );
//	printf ( "%p\n", &apple.num );
//	printf ( "%p\n", &apple.taste );
//	printf ( "%p\n", &apple.color);
//	printf ( "%p\n", &apple.com );
//
//	printf ( "sizeof com: %lu\n", sizeof(apple.com) );
//	printf ( "sizeof apple before: %lu\n", sizeof(apple) );
//	apple.num=100;
//	apple.taste="terrible";
//	apple.color="green";
//	apple.com="apple ,the company is a great company ,it makes great product, iphone, ipad, macbook air is my favorite ";
//	printf ( "%i, %s, %s\n", apple.num, apple.taste, apple.color );
//	printf ( "%s\n", apple.com );
//	printf ( "sizeof apple after: %lu\n", sizeof(apple) );
//	printf ( "sizeof com: %lu\n", sizeof(apple.com) );
	char *s = "fuck u , bitch.\n";
	printf ( "%lu\n", sizeof(*s) );
	return 0;
}

