#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (!argv[1])
		return 1;
	const char *const host = argv[1];
	struct hostent *host_info = 0;
	int attempt = 0;

	for (; (host_info == 0) && (attempt < 3); ++attempt)
		host_info = gethostbyname(host);

	if (host_info) {
		//printf("%s\n",host_info->h_name);
		int i;
		for (i = 0; host_info->h_aliases[i]; ++i) ;
		//printf("%s\n",host_info->h_aliases[i]);

		for (i = 0; host_info->h_addr_list[i]; ++i) {
			struct in_addr *address =
			    (struct in_addr *)host_info->h_addr_list[i];

			printf("%s\n", inet_ntoa(*address));
		}
	} else {
		//herror("error");
		return 2;
	}
	return 0;
}
