#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void method1(void)
{
	char *buf = malloc(512);
	FILE *fs = fopen("longline", "r");
	//fread return 0 if it could not fill all 512
	while (fread(buf, 512, 1, fs) > 0) {
		printf("%s", buf);
	}
	printf("%s", buf);
}

void method2(void)
{
	char *buf = malloc(512);
	FILE *fs = fopen("longline", "r");
	while (fgets(buf, 512, fs) > 0) {
		printf("%s", buf);
	}
}

void method3(void)
{
	FILE *fs = fopen("longline", "r");
	int n;
	while ((n = getc(fs)) != EOF)
		putchar(n);
}

int main(int argc, char *argv[])
{
	method1();
	//method2();
	//method3();
	return 0;
}

