#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int optind=1;
	int j=0;
	char *str=malloc(1000);
	while ( argv[optind] != NULL ) {
		int i=0;
		while (argv[optind][i]){
			switch (argv[optind][i]) {
				case '\'': 
					/*str = realloc(str, j+2);*/
					str[++j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case '/':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case ' ':
					str[j] = '\\';
					str[++j] = ' '; 
					break;
				case '\\':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case '.':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case '*':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case '?':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
				case '$':
					str[j] = '\\';
					str[++j] = argv[optind][i]; 
					break;
//				case '"':
//					str[j] = '\\';
//					str[++j] = argv[optind][i]; 
//					break;
				default:
					/*str = realloc(str, j+1);*/
					str[j] = argv[optind][i];
			}	
			i++;
			j++;
		}
		if ( argv[optind+1])
			str[j] = ' ';
		j++;
		optind++;
	}
	str[j] = '\0';
	printf ( "%s\n", str );
	free(str);
	return 0;
}
