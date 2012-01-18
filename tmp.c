#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int callBack(int (*tmp)(int))
{
	return 9;
}

int tmp(int i)
{
	printf("%i\n", i);
	return i;
}

int main(int argc, const char *argv[])
{
#ifdef BK
	printf("%p\n", tmp);
	callBack(tmp);
#endif /* BK */
#ifdef OLD //{{{
	int i;
	for (i=0; '\0' ;i++)
		puts("fuck");
	char *s="hi";
	for (i=0;i<10;i++)
		putchar(s[i]);
	puts("damn");
	printf("%x\n", EOF);
	return putchar('\0');
#endif //}}}
	fprintf(stderr, "This is an error message.\n");

	FILE *output = popen("less", "w");
	int i;
	for (i = 0; i < 100 ; i++)
		fprintf(output, "wtf\t%i\n", i);

	pclose(output);
	return 0;
}

