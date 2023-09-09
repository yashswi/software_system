#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

int main()
{
	int pid;
	
	int prev_p , new_p;

	struct sched_param p;

	pid = getpid();

	prev_p = sched_getscheduler(pid);

	if(prev_p == -1)
	{
		perror("Error");
		return 1;
	}
	printf("prev scheduling policy is ");
	switch(prev_p)
	{
		case SCHED_FIFO:
			printf("FIFO\n");
			break;

	        case SCHED_RR:
			printf("RR\n");
			break;

		default:
			printf("other\n");
			break;

	}

	new_p = SCHED_FIFO;
	p.sched_priority = 10;

      if(sched_setscheduler(pid,new_p,&p)==-1)
      {
        perror("Error");	 
        return 1;
      }
    printf("changed priority");
 return 0;
}

