
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{

	struct msgbht{
		long mtype;
		char mtext[100];
	}send, recv;

	int msg,len;
	msg=msgget((key_t)29, IPC_CREAT|0666);
       	if(msg<0){
		perror("Message failed");
	       	exit(1);
	}
	for(int i=0;i<4; i++) {

		char temp[100] = "";

		sprintf(temp, "Hello %d ", i+1); 
		strcpy(send.mtext, temp);
		send.mtype=1;
		len=strlen(send.mtext);

		if(msgsnd(msg, &send, len, 0) == -1){ 
			perror("Message failed"); 
			exit(1);
		} 
		//if(msgrcv(msg,&recv, 100,2,0)==-1){ 
		//	perror("Message failed");
		//     	exit(1);
		//}
		//printf("Message from program 2 is: \n%s\n",recv.mtext);
       	}
	return 0;

}


