#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

#define WrongIP -1

unsigned int ip2int(char *s)
{
	int i = 0, j = 0, k = 0;
	char c[4][4];
	for (; s[i] != '\0'; i++) {
		if (s[i] == '.') {
			/*first character can not be '.' and 
			 * the one after  can not be EOF and 
			 * the number can not be over 255 */
			if (i == 0 || s[i + 1] == '\0' || atoi(c[j]) > 255)
				return WrongIP;
			j++;
			k = 0;
			continue;
		}
		c[j][k] = s[i];
		/*False if character is not number */
		if (c[j][k] < '0' || c[j][k] > '9')
			return WrongIP;
		/*only 3 character(0-255) one class can have */
		if (k > 2)
			return WrongIP;
		k++;
		c[j][k] = '\0';
	}
	/*False if more than 4 classes */
	if (j > 3 || atoi(c[j]) > 255)
		return WrongIP;
	/*Fill 0 if the ip is not full format */
	if (j <= 2) {
		strcpy(c[3], c[j]);
		strcpy(c[j], "0");
	}
	if (j == 1)
		strcpy(c[2], "0");
	return atoi(c[0]) * 0x00ffffff + atoi(c[1]) * 0x0000ffff +
	    atoi(c[2]) * 0x000000ff + atoi(c[3]);
}
