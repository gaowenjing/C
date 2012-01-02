#include 	<stdlib.h>

void leak(void)
{
	void *tmp = malloc(1024);
}
int main(int argc, const char *argv[])
{
	while(1) {
		leak();
	}
	return 0;
}

