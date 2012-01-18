#include <stdio.h>
#include <stdlib.h>

#define error(str) \
	{ perror(str); exit(EXIT_FAILURE);}

void leak(void)
{
	void *tmp = malloc(102400000);
	if (!tmp)
		error("malloc")
}

int main(int argc, const char *argv[])
{
	while (1) {
		leak();
	}
	return 0;
}
