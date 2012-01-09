#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

/*recursion function */
int r(int i)
{
	if (i > 0)
		printf("%i\n", i);
	else
		return 0;
	printf("%p\n", r);
	r(--i);
	return 1;
}

int main(int argc, const char *argv[])
{
	r(10) > 0 ? printf("Y\n") : printf("N\n");
	return 0;
}
