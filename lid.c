#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

int main(int argc, const char *argv[])
{
	FILE *f = fopen("/proc/acpi/button/lid/LID/state", "r");
	char s[10];
	fread(s, 19, 1, f);
	printf ( "%s\n", s );
	return 0;
}

