#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isHexChar(char i)
{
	if (
		(i >= '0' && i <= '9') ||
		(i >= 'A' && i <= 'F') ||
		(i >= 'a' && i <= 'f')
	)
	       return 1;
	else
	       return 0;
}

/* Convert a char to hex value 
 * '0' - '9' hex:0x30 - 0x39	->	hex:0x00 - 0x09
 * 'a' - 'f' hex:0x61 - 0x66	->	hex:0x0a - 0x0f
 * 'A' - 'f' hex:0x41 - 0x46
 * */
int convert_to_hex(char i)
{
	if (i & 0x10)/* 0x30 & 0x10 == 0x10 */
		return i & 0x0f;
	else
		return (i & 0x0f) + 0x09;
}

char *urldecode(char *str)
{
	int i, j,
	    n = strlen(str);
	char *buf = malloc(n+1);

	for (i = 0, j = 0; i < n; i++, j++) {
		/* "%ab" -> 0x0a * 0x10 + 0x0b
		 * 'a','b' must be hexchar */
		if (
			str[i] == '%' &&
			isHexChar(str[i+1]) &&
			isHexChar(str[i+2])
		) {
			buf[j] = convert_to_hex(str[i+1]) * 0x10 +
				convert_to_hex(str[i+2]);
			i = i+2;

			/* '+' -> ' ' */
		} else if (str[i] == '+') {
			buf[j] = ' ';
		} else {
			buf[j] = str[i];
		}
	}
	buf[j+1] = '\0';
	return buf;
}

int main(int argc, char *argv[])
{
	char *buf = malloc(512);
	if (argv[1])
		printf("%s\n", urldecode(argv[1]));
	else
		/*while (gets(buf) != NULL)*/
		while (fgets(buf, 512, stdin) > 0)
			printf("%s", urldecode(buf));
	free(buf);
	return 0;
}

