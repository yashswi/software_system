#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    
    for (int i = 0; i < 5; ++i) {
        char file[20];
        snprintf(file, sizeof(file), "file%d.txt", i);

        int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }

        printf("File %s opened successfully with File Descriptor: %d\n", file, fd);
    }

    printf("Process ID: %d\n", getpid());

    // Run an infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}

