
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char* filename = "existing_file.txt";

    
    int fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully . File Descriptor: %d\n", fd);

  
    int fd_excl = open(filename, O_RDWR | O_EXCL);

    if (fd_excl == -1) {
        if (errno == EEXIST) {
            printf("File is already open by another process.\n");
        } else {
            perror("Error opening file with O_EXCL");
            return 1;
        }
    }

    
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    if (fd_excl != -1 && close(fd_excl) == -1) {
        perror("Error closing file with O_EXCL");
        return 1;
    }

    return 0;
}

