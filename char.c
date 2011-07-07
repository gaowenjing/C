#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<error.h>
#include 	"char.h"
//count how many character in a word
int count_char(char *c){
	int j=0;
	while (*(c++) ) {
		j++;
	}
	return j;
}
//delete specific character base on number order (n) 
//1 means the first character ,-1 means backward first character
char *shrink_char(char *word,int n) {
	int wc=count_char(word);
	if (wc<abs(n)) 
		error(1,0,"out of range");
	if (n>=0) {
		return word+n;
	}
	else {
		char *new_word=malloc(sizeof(word)); 
		int i;
		for (i=0;i<(wc+n);i++) 
			*(new_word+i)=*(word+i);
//note: pointer out of range will cause pointer disappear
//		printf ( "%p\n",new_word );
//		printf ( "%c\n",*(new_word+3) );
//		printf ( "%p\n",new_word );
		return new_word;
	}
}

//split one word to two function
sw split_word(char *word , int n) {
	int wc=count_char(word);
	sw r;
	if (n>=0){
		r.left_word=shrink_char(word,n-wc);
		r.right_word=shrink_char(word,n);
	}
	else {
		r.right_word=shrink_char(word,n+wc);
		r.left_word=shrink_char(word,n);
	}
	return r;
}

