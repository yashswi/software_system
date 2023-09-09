#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];
    
    // Open the file for write locking
    fd = open("sample.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("Error opening/creating file");
        return 1;
    }

    // Apply write lock
    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;       // Start of file
    lock.l_len = 0;         // Lock the entire file

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error in applying the WL");
        close(fd);
        return 1;
    }

    // Write to the locked file
    snprintf(buffer, sizeof(buffer), "This is a locked file\n");
    write(fd, buffer, strlen(buffer));

    // Release the lock
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error releasing write lock");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}

