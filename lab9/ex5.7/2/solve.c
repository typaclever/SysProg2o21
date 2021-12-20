#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

struct sockaddr_in local;

int main(int c, char ** v)
{
	if (c != 2)
	{
		printf("Error\n");
		return -1;
	}
	int ss = socket(AF_INET, SOCK_DGRAM, 0);

	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(atoi(v[1]));
	local.sin_family = AF_INET;

	bind(ss, (struct sockaddr*) &local, sizeof(local));

	while(1)
	{
		char buf[BUFSIZ] = "\0";
        	read(ss, buf, BUFSIZ);
        	if (strncmp(buf, "OFF\n", 4) == 0)
        	{
        	        break;
        	}
        	else
        	{
        	        printf("%s\n", buf);
        	}
	}
	close(ss);

	return 0;
}