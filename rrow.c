#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

/*warning: max character in a row is 1023*/
#define MaxRowChar 1024
#define ERROR -1

int main(int argc, const char *argv[])
{
	if (argv[2] == NULL)
		return ERROR;
	FILE *fs = fopen (argv[1], "r");
	if (fs == NULL)
		return ERROR;
	/*read row value*/
	int i=1;
	int row = atoi(argv[2]);
	char str[MaxRowChar];
	while (i<= row)
	{
		fgets (str, MaxRowChar, fs);
		i++;
	}
	printf ( "%s", str );
	fclose(fs);
	return 0;
}

