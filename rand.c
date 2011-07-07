#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef RAND_MAX
#undef RAND_MAX
#endif
#define RAND_MAX 100

int main(int argc, const char *argv[])
{
//	printf ( "%i\n",RAND_MAX );
//	srand(time(NULL));
//	printf ( "%i\n",rand() );
//	printf ( "%i\n",rand() );
//	unsigned int *i=malloc(1);
//	printf ( "%p\n",i );
//	printf ( "%i\n",rand_r(i) );
//	free(i);
	printf ( "%f\n",drand48() );
	return 0;
}
