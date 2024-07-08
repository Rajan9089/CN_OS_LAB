// client

#include<stdio.h>

#include<ctype.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<fcntl.h>
#include <unistd.h> // Added for write and read functions
#include<stdlib.h>

#include<string.h>

int main() {

int wrfd, rdfd,n;

char buf[50],line [50];

wrfd=open("np1", O_WRONLY); 
rdfd=open("np2", O_RDONLY);

printf("Enter the line of text: ");

//gets(line);
//fgets(line, 50 , stdin);
fgets(line, sizeof(buf), stdin);
write(wrfd, line, strlen(line));

n=read(rdfd, buf, 50);

buf[n]='\0';

printf("Full duplex client read from pipe: %s\n", buf);

// Close file descriptors
//close(wrfd);
//close(rdfd);
//close(n);
return 0;

}
