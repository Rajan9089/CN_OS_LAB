#include<stdio.h>
#include<sys/types.h>

#include<fcntl.h>
#include <sys/stat.h> // Include for mkfifo
#include <unistd.h> // Added for write and read functions
#include <ctype.h>
#include<stdlib.h>

#include<string.h>

int main(){

int wrfd, rdfd,n, d, ret_val, count;

char buf[50];

ret_val = mkfifo("np1", 0666); 

//if(ret_val<0) {
// printf("Unable to create a fifo");
 //exit(-1);
//}
ret_val = mkfifo("np2", 0666);

//if(ret_val<0) {
 //printf("Unable to create a fifo");
 //exit(-1);
//}
rdfd = open("np1", O_RDONLY);
wrfd = open("np2", O_WRONLY);

n=read(rdfd, buf, 50);

buf[n] = '\0';

printf("Full duplex server : read from the pipe: %s\n", buf);

count = 0;

while(count < n)
{
	buf[count] = toupper(buf[count]);
	count++;	
}
write(wrfd, buf, strlen(buf));
// Close file descriptors
//close(wrfd);
//close(rdfd);
//close(n);
return 0;
}
