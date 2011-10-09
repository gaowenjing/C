#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define QQWRY "QQWry.Dat"
#define QQWRY "gwj"

int main(int argc, const char *argv[])
{
	FILE *fs = fopen(QQWRY, "r");
	if (fs == NULL) 
		perror("fopen"); 
	unsigned long ptr;
	printf ( "%lu\n", sizeof(ptr) );
	fread(&ptr, 11, 1, fs);
	printf ( "%.02lx\n", ptr);
//	printf ( "%x\n", ptr&0x0000ffff );

	fclose(fs);
	return 0;
}

