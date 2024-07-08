#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <stdio.h>

int main()
{

	int msgid;

	key_t key;
	int mykey;

	msgid = msgget((key) | 5, IPC_CREAT | 06444);
	if (msgid < 0)
	{
		perror("Message failed");
	}
	else
	{
		printf("Message queue is created with key value %d ", msgid);
	}
}
