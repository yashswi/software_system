#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


int main() {

    int tkt = 0;

    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Write the initial ticket number to the file
    if (write(fd, &tkt, sizeof(tkt)) == -1) {
        perror("Failed ");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    printf("Initial ticket number written to the file.\n");

    return 0;
}

