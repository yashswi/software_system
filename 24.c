#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int pid = fork();

	if(pid>0)
	{
		printf("parent pid %d.\n",getpid());
		exit(0);

	}

	 else 
	{       
		printf("child process id %d.\n",getpid());
		sleep(10);
		printf("parent pid id %d.\n", getppid()); 
		
	}
	return 0;
}

