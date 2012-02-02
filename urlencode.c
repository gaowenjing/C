#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void urlencode(char *string)
{
	int i;
	for (i = 0; string[i] ; i++) {
		/* the character need to escape is based on wikipedia
		 * http://en.wikipedia.org/wiki/Percent-encoding
		 * */
		switch (string[i]) {
		case 'A' ... 'Z':
		case 'a' ... 'z':
		case '0' ... '9':
		case '.':
		case '-':
		case '_':
		case '~':
			putchar(string[i]);
			break;
		default:
			printf("%%%02x", string[i] & 0x000000ff);
		}
	}
	fflush(stdout);
}

int main(int argc, char *argv[])
{
	char *buf = malloc(512);
	if (argv[1])
		urlencode(argv[1]);
	else
		while (fgets(buf, 512, stdin) > 0) {
			urlencode(buf);
		}
	free(buf);
	return 0;
}

