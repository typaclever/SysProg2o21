#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in local;

int main(int c, char **v)
{
	if (c != 2)
	{
		printf("Error\n");
		return -1;
	}

	int s = socket(AF_INET, SOCK_STREAM, 0);
	int cs;

	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(atoi(v[1]));
	local.sin_family = AF_INET;

	bind(s, (struct sockaddr*) &local, sizeof(local));
	listen(s, 5);

	cs = accept(s, NULL, NULL);

	char ch;
	int i, j;
	while (1)
	{
		char buf[BUFSIZ] = "\0";
		read(cs, buf, BUFSIZ);
		buf[BUFSIZ + 1] = '\0';
		if (strncmp(buf, "OFF\n", 4) == 0)
			break;
		for (i = 0; i < strlen(buf) - 1; i++)
		{
			for (j = 0; j < strlen(buf) - 1 - i; j++)
			{
				if (buf[j] < buf[j+1])
				{
					char tmp = buf[j];
					buf[j] = buf[j+1];
					buf[j+1] = tmp;
				}
			}
		}
		write(cs, buf, strlen(buf) + 1);
	}
	close(cs);
	return 0;
}