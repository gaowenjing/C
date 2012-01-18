#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int show_hostname = 0;
int show_cname = 0;
int show_request = 0;

void usage(char *name)
{
	printf("Usage: %s [Options] hostname\n", name);
	printf("\t-o show hostname (hosts file format).\n");
	printf("\t-i show CNAME or alias name.\n");
	printf("\t-r show request.\n");
	printf("\t-h show this message.\n");
	exit(EXIT_SUCCESS);
}

int queryIP(char *host)
{
	struct hostent *host_info = 0;
	int attempt = 0;

	for (; (host_info == 0) && (attempt < 3); ++attempt)
		host_info = gethostbyname(host);

	if (host_info) {
		if (show_request)
			printf("%s\n",host_info->h_name);
		int i;
		if (show_cname)
			for (i = 0; host_info->h_aliases[i]; ++i) 
				printf("%s\n",host_info->h_aliases[i]);

		for (i = 0; host_info->h_addr_list[i]; ++i) {
			struct in_addr *address =
			    (struct in_addr *)host_info->h_addr_list[i];

			if (show_hostname)
				printf("%s %s\n", inet_ntoa(*address), host);
			else
				printf("%s\n", inet_ntoa(*address));
		}
	} else {
		herror("error");
		return 2;
	}
	return 0;
}

void handleArgs(int argc, char *argv[])
{
	int opt;
	while ((opt = getopt(argc, argv, "hior")) != -1) {
		switch (opt) {
		case 'i':
			show_cname = 1;
			break;
		case 'o':
			show_hostname = 1;
			break;
		case 'r':
			show_request = 1;
			break;
		case 'h':
		default:
			usage(argv[0]);
		}
	}
}


int main(int argc, char *argv[])
{
	if (!argv[optind])
		usage(argv[0]);

	handleArgs(argc, argv);
	
	return queryIP(argv[optind]);
}
