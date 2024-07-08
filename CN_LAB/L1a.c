#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <stdio.h>

int main()
{

	int msgid;

	key_t key;

	int mykey;
	// Generating a Key for the Message Queue
    key = ftok(".", 'a'); 
	// ftok function generates a key based on a file and a character

	msgid = msgget((key) | mykey, IPC_CREAT | 0);

	printf("Message queue is created with key value %d ", msgid);
}
