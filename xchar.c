#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAXBUF 1024
#define SED 1
#define SQL 2

// Characters need to be escape.
char sedCharacter[] = {'\'', '/', ' ', '\\', '.', '*', '?', '$', '[', ']', '\0'};

char sqlCharacter[] = { '\'', '\0'};

// The escape function
// int specify : SED :escape for sed ; SQL :escape for sql 
// char *string : The string need to be escap
char *escape(char *string, int specify)
{
	int i, j, x;
	static char new[MAXBUF];
	char escapeCharacter = '\\';            /* Default Sed */
	char *specificCharacter = sedCharacter;
	// Which Characters list
	switch ( specify ) {
		case SED:
			specificCharacter = sedCharacter;
			escapeCharacter = '\\';
			break;
		case SQL:
			specificCharacter = sqlCharacter;
			escapeCharacter = '\'';
			break;
	}

	for (i=0, j=0; string[i]; i++, j++)
	{
		for (x=0; specificCharacter[x]; x++)
		{
			if (string[i] == specificCharacter[x])
			{
				new[j] = escapeCharacter;
				j++;
				break;
			}
		}
		new[j] = string[i];
	}
	new[j] = '\0';
	return new;
}

int main(int argc, char *argv[])
{
	int opt, flag=SQL;
	char *file = NULL;
	while((opt = getopt(argc, argv, "f:sq")) != -1){

		switch ( opt ) {
			case 'f':
				file = argv[optopt];
				break;
			case 's':	
				flag = SED;
				break;
			case 'q':	
				flag = SQL;
				break;
			default:
				return 1;
		}
	}
	if (argv[optind])
		puts(escape(argv[optind], flag));
	else 
	{
		char tmp[MAXBUF];
		while( fgets(tmp, MAXBUF, stdin) )
			//puts(escape(tmp, flag));
			printf("%s", escape(tmp, flag));
	}
	return 0;
}
