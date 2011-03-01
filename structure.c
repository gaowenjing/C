#include <stdio.h>
void main(){
	struct people {
		char *name;
		int age;
		char *sex;
		char *addr;
		char *mail;
		char habit[16][1];
		//char *habit;
		char content[0];
	};
	struct people no1 = { "gwj",27,"male" };
	no1.addr = "sjdfklasdjffsjdf ksd fjs sd fs df sdf sdjfksd f";
//	struct people *no2 = { 23423 } ;
//	printf ("%s,%d,%s\n" ,no1.name,no1.age,no1.sex );
//	printf ("%s,%d,%s\n",(struct people *) &no1);
//	printf ("%s\n",no1.addr);
	printf ("%d\n",sizeof(struct people));
	printf ("pointer value:%d\n",*no1.addr);
	printf ("pointer add :%p\n",&no1.addr);
	printf ("value :%s\n",no1.addr);
	printf ("--------------------------------------------int\n");
	int i =  345345,j = 567567;
	int *ip = &i;
	printf ("%p\n",ip);
	printf ("%d\n",*ip);
	printf ("%p\n",&ip);
	printf ("--------------------------------------------\n");
	ip = &j;
//	i = 123123;
	printf ("%p\n",ip);
	printf ("%d\n",*   ip);
	printf ("%p\n",&ip);
	printf ("--------------------------------------------\n");
//	ip = &i;
	*ip = 106;
	printf ("%i\n",j);
	printf ("%p\n",&ip);
	printf ("--------------------------------------------char\n");
	char *ic = "djsflksdjfs kdfs dfklajd fa" ;
	printf ("%s\n",ic);
	printf ("%i\n",*ic);
	printf ("%p\n",&ic);
	printf ("--------------------------------------------\n");
	ic = "jdfosdfnsfnwoef";
	printf ("%s\n",ic);
	printf ("%d\n",*ic);
	printf ("%p\n",&ic);

}
