#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int callBack(int (*tmp)())
{
	printf("%i\n", tmp(45));
	return 9;
}

int tmp(int i)
{
	return i;
}

int main(int argc, const char *argv[])
{
	//printf("%p\n", tmp);
	//callBack(tmp);
	//printf("%i\n", argc);
	//return putchar(NULL);
	//if ( '\n' ) puts("fuck");
#ifdef OLD
	int i;
	for (i=0; '\0' ;i++)
		puts("fuck");
	char *s="hi";
	for (i=0;i<10;i++)
		putchar(s[i]);
	puts("damn");
	printf("%x\n", EOF);
	return putchar('\0');
#endif
	return 10 == 11;
}

