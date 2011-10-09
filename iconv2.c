#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <iconv.h>

#define DEF_BUF 1024
#define FROMCODE "gbk"
#define TOCODE "utf8"

/*use iconv convert FROMCODE to TOCODE*/
char *iconv_convert (char *inbuf)
{
	/*iconv_open */
	iconv_t cd = iconv_open(TOCODE, FROMCODE);
	if (cd == (iconv_t)-1) 
		fprintf (stderr, "CAN NOT COVERT ");
	/*converting */
	size_t inlen = strlen(inbuf);
	size_t outlen = inlen*2;
	char *outbuf = malloc(outlen);
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
	return outbuf;
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
		fprintf (stderr, "ERROR ON CONVERTING.\nERRNO == ");
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

int main(int argc, char *argv[])
{
	char *inbuf = malloc(DEF_BUF);
	if (argv[1] == NULL)
	{
		fread (inbuf, DEF_BUF, 1, stdin);
//		scanf("%s", inbuf);
	}
	else 
		inbuf = argv[1];
//	char *outbuf = malloc(strlen(inbuf));
//	convert (inbuf, outbuf);
//	printf ( "%s\n", outbuf );
	char *output = iconv_convert(inbuf);
	printf("%s\n", output);
//	printf ( "%s\n", iconv_convert(inbuf) );
//	printf ( "%s\n", inbuf );
	return 0;
}
