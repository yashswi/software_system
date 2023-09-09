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
#include <unistd.h> 
#include <stdio.h>  

int main()
{
    char *arguments[]={"ls", "-Rl", NULL}; 
    execvp("ls", arguments);
    printf("\n This printf statement will execute if execvp fails!!!");

    return 0;
}
