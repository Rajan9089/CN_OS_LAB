#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

	int pipefd[2], n;
	char buff[100];
	pipe(pipefd);
	printf("\n readfd = %d ", pipefd[0]);
	printf("\n writefd = %d ", pipefd[1]);

	//write(pipefd[1], "Rajan", 5);
	//write(pipefd[1], "Rajan kumar", 12);
	write(pipefd[1], "Rajan-kumar", 12);
	n = read(pipefd[0], buff, sizeof(buff));

	printf("\n size of data %d", n);

	printf("\n data from pipe: %s", buff);
	return 0;
}
