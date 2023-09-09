#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int pid = fork();

	if(pid)
	{
		sleep(100);
	}
	else 
	{
		exit(0);
	}
	return 0;
}

