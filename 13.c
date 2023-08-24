#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    fd_set fds;
    struct timeval to;

    FD_ZERO(&fds);          // Clear the set
    FD_SET(STDIN_FILENO, &fds);  // Add stdin to the set

    to.tv_sec = 10;        // Timeout  10 sec
    to.tv_usec = 0;

    printf("Wait up to 10 seconds...\n");

    int ready = select(STDIN_FILENO + 1, &fds, NULL, NULL, &to);

    if (ready == -1) {
        perror("select");
        return EXIT_FAILURE;
    } else if (ready == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            printf("Data is available on stdin.\n");
        }
    }

    return EXIT_SUCCESS;
}

