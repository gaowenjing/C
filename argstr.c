#include <stdlib.h>
#include <stdio.h>

//argv to string 

/*return size of a word*/
size_t slen(char *word){
	char *c=word;
	while (*(word++));
	return word-c;

}
/*copy words */
void scp(char *from, char *to){
	while (*from)
		*(to++) = *(from ++);
}
/*add addition words to a string*/
void sadd(char *original, char *addition){
	while (*(original++));
	*(original-1) = ' ';
	while (*addition)
		*(original++) = *(addition++);
}
/*make argv a whole string*/
char *argstr(int argc, char *argv[], int optind){
	char *str = malloc(slen(argv[optind]));
	scp(argv[optind], str);
	int i;
	for (i = optind+1; i < argc; i++) {
		str = realloc(str, slen(str)+slen(argv[i])+1);
		sadd(str, argv[i]);
	}
	return str;
}
