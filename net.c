#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd < 0)
		perror("socket");
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(7000);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sfd, (struct sockaddr *)&address, sizeof(address)) < 0)
		perror("bind");
	if (listen(sfd, 1) < 0)
		perror("listen");
	socklen_t size = sizeof(address);
	if (accept(sfd, (struct sockaddr *)&address, &size) < 0)
		perror("accept");
	close(sfd);
	shutdown(sfd, 2);
	return 0;
}
