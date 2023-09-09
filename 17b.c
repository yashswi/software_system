/*
============================================================================
Name : 17b.c
Author : yashswi Chaturvedi
Description :Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 15 Aug, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

int main() {
    
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // Lock the entire file

    
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to apply write lock");
        close(fd);
        return 1;
    }

    // Read the current ticket number from the file
    int tkt;

    if (read(fd, &tkt, sizeof(tkt)) == -1) {
        perror("Failed to read from file");
        close(fd);
        return 1;
    }

    
    tkt++;

    // Rewind the file pointer to the beginning
    lseek(fd, 0, SEEK_SET);

    //  updated ticket no back to the file
    if (write(fd, &tkt, sizeof(tkt)) == -1) {
        perror("Failed to write to file");
        close(fd);
        return 1;
    }

    // Release the WL
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
    }

   
    close(fd);

    printf("updated ticket number: %d\n", tkt);

    return 0;
}

