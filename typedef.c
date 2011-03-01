#include <stdio.h>

//typedef int gwj;
//
//int main (){
//	gwj age=123;
//	printf ("%d\n",age);
//	return 0;
//
//}

typedef struct people {
	int number;
	char *name;
	int age;
	char *sex;
}PEOPLE;

int main (){
	PEOPLE no1 = { 1,"gwj",0,"male" };
	no1.age = 100;
	printf ("%d,%s,%i\n",no1.number,no1.name,no1.age);
	printf ("%p,%p\n",&no1,&no1.number);
	return 0;
}
