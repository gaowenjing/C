#include <stdio.h>

int main (void ){
	union numbers {
		double f;
		int i;
	} gwj = { .f = 232.232 } ;
	//union numbers gwj = { f: 2392.232 };
//	union numbers gwj = { 92 };
//	gwj.i = 23;
//	gwj.f = 233.232;	
	printf ("%f\n",gwj.f);
	printf ("%i\n",sizeof(gwj));
	return 0;
}
