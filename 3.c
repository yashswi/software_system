#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a file named "example.txt" with read and write permissions
    int fd = creat("example.txt", S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully. File Descriptor: %d\n", fd);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

