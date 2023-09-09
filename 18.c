#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define FILENAME "recordfile.txt"
#define RECORD_SIZE 100

void write_lock(int fd, int rec_no) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_no * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed");
        exit(1);
    }
}

void read_lock(int fd, int rec_no) {
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_no * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire read lock");
        exit(1);
    }
}

void unlock(int fd, int rec_no) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_no * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
        exit(1);
    }
}

int main() {
    int fd = open(FILENAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    int rec_no = 0;

    //  write lock and modify the record
    write_lock(fd, rec_no);

    printf("Writing to record %d...\n", rec_no);
    char data[] = "Yashswi Chaturvedi";

    lseek(fd, rec_no * RECORD_SIZE, SEEK_SET);
    write(fd, data, strlen(data));
    unlock(fd, rec_no);

    // apply read lock and read the modified record
    read_lock(fd, rec_no);
    printf("Reading from record %d...\n", rec_no);
    char read_data[RECORD_SIZE];

    lseek(fd, rec_no * RECORD_SIZE, SEEK_SET);
    read(fd, read_data, sizeof(read_data));
    printf("Record content: %s\n", read_data);
    unlock(fd, rec_no);

    close(fd);

    return 0;
}

