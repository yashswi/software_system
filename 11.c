#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void duplicateUsingDup(int fd, const char *content) {
    int new_fd = dup(fd);

    if (new_fd == -1) {
        perror("dup");
        exit(EXIT_FAILURE);
    }

    // Append using original descriptor
    write(fd, content, strlen(content));
    printf("Appended using dup descriptor.\n");

    // Append using duplicated descriptor
    write(new_fd, content, strlen(content));
    printf("Appended using duplicated descriptor.\n");

    close(new_fd);
}

void duplicateUsingDup2(int fd, const char *content) {
    int new_fd = dup2(fd, 100);  // Using a specific file descriptor number (100) for demonstration

    if (new_fd == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    // Append using original descriptor
    write(fd, content, strlen(content));
    printf("Appended using dup2 original descriptor.\n");

    // Append using duplicated descriptor
    write(new_fd, content, strlen(content));
    printf("Appended using dup2 duplicated descriptor.\n");

    close(new_fd);
}

void duplicateUsingFcntl(int fd, const char *content) {
    int new_fd = fcntl(fd, F_DUPFD, 0);

    if (new_fd == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    // Append using original descriptor
    write(fd, content, strlen(content));
    printf("Appended using fcntl original descriptor.\n");

    // Append using duplicated descriptor
    write(new_fd, content, strlen(content));
    printf("Appended using fcntl duplicated descriptor.\n");

    close(new_fd);
}

int main() {
    const char *filename = "sample.txt";
    const char *content = "Hello, this is additional content!\n";

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    duplicateUsingDup(fd, content);
    lseek(fd, 0, SEEK_SET);  // Reset file pointer

    duplicateUsingDup2(fd, content);
    lseek(fd, 0, SEEK_SET);  // Reset file pointer

    duplicateUsingFcntl(fd, content);

    close(fd);
    
    return EXIT_SUCCESS;
}

