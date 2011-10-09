#include <stdlib.h>
#include <stdio.h>

//argv to string 

/*return size of a word not include the '\0'*/
size_t slen(char *word){
	char *c=word;
	while (*c)
		c++;
	return c-word;

}
/*copy words */
void scp(char *from, char *to){
	size_t i=0;
	while (*(from+i)){
		*(to+i) = *(from+i);
		i++;
	}
	*(to+i) = '\0';
}
/*add addition words to a string assume original size enough*/
void sadd(char *original, char *addition){ 
	size_t o_len = slen(original);
	size_t a_len = slen(addition);
	size_t i = 0;
	*(original+o_len) = ' ';
	for ( ; i < a_len ; i++)
		*(original+o_len+i+1) = *(addition+i);
	*(original+o_len+a_len+1) = '\0';
}
/*make argv a whole string*/
char *argstr(int argc, char *argv[], int f){
	char *str = malloc(slen(argv[f]));
	scp(argv[f], str);
	int i;
	for (i = f+1; i < argc; i++) {
		str = realloc(str, slen(str)+slen(argv[i])+1);
		sadd(str, argv[i]);
	}
	return str;
}

