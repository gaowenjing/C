#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *isQuote(char *string)
{
	int i, j;
	static char new[1024];
	for (i = 0, j = 0; string[i]; i++, j++) {
		//for (i=0; putchar(string[i]); i++) {
		if (string[i] == '\'')
			//return "is quote";
		{
			new[j] = '\'';
			j++;
		}
		new[j] = string[i];
		//usleep(100000);
		//puts(new);
		//fflush(NULL);
	}
	new[j] = '\0';
	return new;
}

int main(int argc, const char *argv[])
{
	FILE *fs = fopen("/home/gwj/tmp/www.csdn.net.sql", "r");
	char tmp[1024];
	//while (fread (tmp, 1024, 1, fs))
	while (fgets(tmp, 1024, fs))
		//puts(tmp)
	{
		//if (isQuote(tmp));
		//puts(tmp);
		if (strcmp(tmp, isQuote(tmp)))
			puts(isQuote(tmp));
	}
	return 1;
}
