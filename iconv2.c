#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <iconv.h>

#define MAXBUF 256
#define FROMCODE "gbk"
#define TOCODE "utf8"

/*use iconv convert FROMCODE to TOCODE*/
char *iconv_return (char *inbuf)
{
	/*iconv_open */
	iconv_t cd = iconv_open(TOCODE, FROMCODE);
	if (cd == (iconv_t)-1) 
		fprintf (stderr, "CAN NOT COVERT ");
	/*converting */
	size_t inlen = strlen(inbuf);
	/*Chinese char: gbk 2 bytes/char, utf8 3 bytes/char*/
	size_t outlen = inlen*2;
//	static char outptr[MAXBUF];
	char *outptr = malloc(outlen);
	char *outbuf = outptr;
	size_t rc = iconv(cd, &inbuf, &inlen, &outbuf, &outlen);
	if (rc == (size_t) -1)
	{
		fprintf (stderr, "ERROR ON CONVERTING. ERRNO: ");
		switch (errno)
		{
			case E2BIG:
				fprintf (stderr, "E2BIG\n");
				break;
			case EILSEQ:
				fprintf (stderr, "EILSEQ\n");
				break;
			case EINVAL:
				fprintf (stderr, "EINVAL\n");
				break;
		}
	}
	iconv_close(cd);
	return outptr;
}

void convert (char *inbuf, char *outbuf)
{
	/*iconv_open */
	iconv_t cd = iconv_open(TOCODE, FROMCODE);
	if (cd == (iconv_t)-1) 
		fprintf (stderr, "ERROR ON START CONVERT\n");
	/*converting */
	size_t inlen = strlen(inbuf);
	size_t outlen = inlen*2;
	size_t rc = iconv(cd, &inbuf, &inlen, &outbuf, &outlen);
	if (rc == (size_t) -1)
		fprintf (stderr, "ERROR ON CONVERTING.ERRNO: ");
	switch (errno)
	{
		case E2BIG:
			fprintf (stderr, "E2BIG\n");
			break;
		case EILSEQ:
			fprintf (stderr, "EILSEQ\n");
			break;
		case EINVAL:
			fprintf (stderr, "EINVAL\n");
			break;
	}
	iconv_close(cd);
}

void read_stdin (char *inbuf, size_t len)
{
	size_t n;
	while (1)
	{
		n = fread(inbuf, len, 1, stdin);
		if (n < len)
			break;
	}
}

int main(int argc, char *argv[])
{
	char inbuf[MAXBUF];
	char outbuf[MAXBUF*2];
	int n;
	if (argv[1] == NULL)
	{
		while ( (fgets(inbuf, MAXBUF, stdin)) != NULL )
		{
			convert (inbuf, outbuf);
			printf ( "%s\n", outbuf );
//			printf("%s\n", inbuf);
		}
	}
//	else 
//		inbuf = argv[1];

//	printf("-------------------convert()--------------------\n");

//	printf("-----------------iconv_return()------------------\n");
//	printf ( "%s\n", iconv_return(inbuf) );
//	free(inbuf);
//	free(outbuf);
	return 0;
}
