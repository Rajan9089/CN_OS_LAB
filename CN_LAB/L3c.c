#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	int p1[2], p2[2], n, pid;
	char buf1[25], buf2[25];

	pipe(p1);
	pipe(p2);
	printf("\n readfds %d %d", p1[0], p2[0]);
	printf("\n writefds %d %d", p1[1], p2[1]);

	pid = fork();
	if (pid == 0)
	{

		close(p1[0]);

		printf("\nCHILD PROCESS SENDING DATA\n");

		write(p1[1], "Where is GCE", 13);

		close(p2[1]);

		read(p2[0], buf1, 25);

		printf("Reply from Parent: %s\n", buf1);
	}
	else
	{
		close(p1[1]);

		printf("\nPARENT PROCESS RECIEVING DATA\n");
		read(p1[0], buf2, sizeof(buf2));
		printf("\nData recieved from child through pipe: %s\n", buf2);
		sleep(3);
		close(p2[0]);
		write(p2[1], "In Haldia", 10);
		printf("\n Reply Send\n");
	}
	return 0;
}
