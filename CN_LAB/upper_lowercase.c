#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
int main() 
{

int pipefd[2];
pid_t pid;

if (pipe(pipefd) == -1) {
	perror("pipe");
	exit(EXIT_FAILURE);
}

pid = fork();
if (pid == -1) {
	perror("fork");
	exit(EXIT_FAILURE);
}

if (pid == 0) { 
	close(pipefd[0]); 	
	char input[BUFFER_SIZE];
	printf("Enter a string in uppercase: ");
	fgets(input, BUFFER_SIZE, stdin);
	
	for (int i = 0; input[i]; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] += ('a' - 'A'); 
		}			
	}
	
	write(pipefd[1], input, strlen(input)+1);
	close(pipefd[1]); 
	exit(EXIT_SUCCESS);
} else { 
	close(pipefd[1]); 
	
	char output[BUFFER_SIZE];
	read(pipefd[0], output, BUFFER_SIZE);
	printf("Converted string: %s", output);
	close(pipefd[0]); 
	wait(NULL); 
}

return 0;

}
