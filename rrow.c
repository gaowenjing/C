#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

/*warning: max character in a row is 1023*/
#define MaxRowChar 512
#define ERROR -1

int main(int argc, const char *argv[])
{
	if (argv[2] == NULL)
		return ERROR;
	FILE *fs = fopen(argv[1], "r");
	if (fs == NULL)
		return ERROR;
	/*read row value */
#define OLD
#ifdef OLD
	int i = 1;
	int row = atoi(argv[2]);
	char str[MaxRowChar];

	while (i <= row) {
		fgets(str, MaxRowChar, fs);
		if (str[MaxRowChar - 1] != '\0')
			continue;
		putchar(str[MaxRowChar - 1]);
		i++;
	}
	printf("%s", str);
#endif
	fclose(fs);
	return 0;
}
