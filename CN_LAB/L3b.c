
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

	int pipefd[2], n, pid;

	char buff[100];

	pipe(pipefd);

	printf("\n readfd %d", pipefd[0]);
	printf("\n writefd = %d ", pipefd[1]);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		printf("\nCHILD PROCESS SENDING DATA\n");
		write(pipefd[1], "Hello World", 12);
	}

	else
	{

		close(pipefd[1]);

		printf("\nPARENT PROCESS RECIEVING DATA\n");

		n = read(pipefd[0], buff, sizeof(buff));

		printf("\nsize of data %d ", n);
		printf("\ndata recieved from child through pipe: %s", buff);
	}
	return 0;
}
