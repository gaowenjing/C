#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>

int main(int argc, char *argv[])
{
	if ( argv[1] == NULL )
		exit(1);
	int opt;
	int e_flag=0;
	char *cmd[2];
	while ( (opt = getopt(argc, argv, "e:e:")) !=  -1 ) {
		switch (opt) {
			case 'e':
				cmd[e_flag]=optarg;
				e_flag++;
				break;
		}
	}
	printf ( "cmd[0] = %s\n", cmd[0] );
	printf ( "cmd[1] = %s\n", cmd[1] );
	return 0;
}

