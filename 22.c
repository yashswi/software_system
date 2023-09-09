#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{       
	int fd = open("ABC.txt",O_RDWR,0644);
	  if(fd==-1)
           {
		   perror("Error opening the file");
		   return 1;
	   }

	 int pid = fork();

	 if(pid)
	 {
           const char d1[]="parent process";
           ssize_t byt= write(fd,d1,sizeof(d1)-1);
                 
	   if(byt ==-1)
            {
           perror("error writting data");
           close(fd);
           return 1;
            }
         }
	 else 
	  {
	   const char d1[]="child process";
           ssize_t byt= write(fd,d1,sizeof(d1)-1);

           if(byt ==-1)
            {
           perror("error writting data");
           close(fd);
           return 1;

	  }
        }	   
	   close(fd);
	   return 0;
 }

