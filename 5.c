#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
    
    while(1){
  creat("f1.txt", O_CREAT);
  creat("f2.txt", O_CREAT);
  creat("f3.txt", O_CREAT);
  creat("f4.txt", O_CREAT);
  creat("f5.txt", O_CREAT);
  }



