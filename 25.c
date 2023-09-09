#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/wait.h>

int main(void)
{
	int cid1,cid2,cid3;
	  cid1= fork();

	 if(cid1==0)
	 {
		 printf("inside c1 with pid %d\n", getpid());
		 sleep(5);
		 printf("exit c1");
	 }
	 else if((cid2=fork())==0)
	   {
	     printf("\n inside chid2 pid %d\n", getpid());
	     sleep(15);
	     printf("exit child2");
	    }

	   else if((cid3=fork()) == 0)
	    {
	      printf("\ninside child3 pid %d\n",getpid());
	      sleep(15);
	      printf("Exit child3\n");
	     }

	     else
	     {
	       int w=  waitpid(cid1, NULL, 0);
	       printf("\nExit the parent process \n");
	     }
	     return 0;
     
}
