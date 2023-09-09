#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int pid = fork();

	if(pid==0)
	{
		printf("This is a child process %d.\n",getpid());

	}
	else 
	{
		printf("this is a parent process %d.\n",getpid());
	}
	return 0;
}
