#include <stdio.h>
#include "char.h"

int main(int argc, char *argv[])
{
	
	char *s="fsjd\\sjod\nfs\"jd'sk'd'f'j/ \"fjdsof";
	char t[]="fsjd\\sjod\nfs\"jd'sk'd'f'j/ \"fjdsof";
	printf ( "%lu\n",sizeof(s) );
	printf ( "%i\n",count_char(s) );
	printf ( "%s\n",s );
	printf ( "%s\n",argv[1] );
	printf ( "%lu\n",sizeof(argv[1]) );
	printf ( "%i\n",count_char(argv[1]) );
	printf ( "%i\n",count_char(t) );
	printf ( "%lu\n",sizeof(t) );
	return 0;
}
