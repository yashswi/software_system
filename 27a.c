#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
          printf("execl:\n");
          execl("/bin/ls", "ls", "-Rl", NULL);
          perror("execl");
          return 0;
 }

