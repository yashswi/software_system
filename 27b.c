/*
============================================================================
Name : 27b.c
Author : yashswi Chaturvedi
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 5th sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("execlp:\n");
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
   
  return 0;
}
