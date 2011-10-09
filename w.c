#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

int main(int argc, const char *argv[])
{
	FILE *fs =  fopen("gwj", "r+");
	if (fs == NULL)
		perror("fopen");
	/*const char *buf = "fuck u, bitch.\n";*/
	/*int buf = 1000;*/
	char buf[10];
	sprintf(buf, "%d\n", 1000);
	fwrite (buf, strlen(buf), 1, fs);
	/*size_t s = fwrite (buf, strlen(buf), 1, fs);*/
	/*printf ( "%lu\n", s );*/
	fclose(fs);
	return 0;
}

