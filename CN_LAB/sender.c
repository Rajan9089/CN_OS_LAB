#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{

	struct msgbht
	{

		long mtype;
		char mtext[100];

	} send, recv;

	int msg, len;
	msg = msgget((key_t)29, IPC_CREAT | 0666);

	if (msg < 0)
	{
		perror("Message failed");
		exit(1);
	}
	strcpy(send.mtext, "I am fine thankyou.");

	send.mtype = 2;

	len = strlen(send.mtext);

	if (msgrcv(msg, &recv, 100, 1, 0) == -1)
	{
		perror("Message failed");
		exit(1);
	}
	if (msgsnd(msg, &send, len, 0) == -1)
	{
		perror("Message failed");
		exit(1);
	}
	printf("Message from program 1 is : \n%s\n", recv.mtext);
}
