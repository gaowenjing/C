#include <stdio.h>
#include </home/gwj/lab/gwj.h>

int main (int argc , char** argv){
	printf ("%d\n",ZERO);
	char* s="sdofisndfsdf";
	printf ("%s\n",s);
	printf ("%p\n",*s);
	printf ("%p\n",&s);
//	char t[0];
//	scanf ("%s",t);
//	perror ("scanf");
//	printf ("%s\n",t);
	if ( gwj() != 0 ) 
		printf ("%u",sizeof(gwj()));
	return 0;
}
