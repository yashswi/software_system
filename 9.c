#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error provide the 2nd argument ");//file name is not given 
        return 1;
    }

    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("Error");
        return 1;
    }

    printf("File Information for: %s\n", argv[1]);
    printf("a. Inode: %lu\n", (unsigned long)sb.st_ino);
    printf("b. Number of Hard Links: %lu\n", (unsigned long)sb.st_nlink);
    printf("c. UID: %u\n", sb.st_uid);
    printf("d. GID: %u\n", sb.st_gid);
    printf("e. Size: %ld bytes\n", (long)sb.st_size);
    printf("f. Block Size: %ld bytes\n", (long)sb.st_blksize);
    printf("g. Number of Blocks: %lld\n", (long long)sb.st_blocks);

    // Convert time to a string representation
    char access_time[20], modify_time[20], change_time[20];
    strftime(access_time, sizeof(access_time), "%Y-%m-%d %H:%M:%S", localtime(&sb.st_atime));
    strftime(modify_time, sizeof(modify_time), "%Y-%m-%d %H:%M:%S", localtime(&sb.st_mtime));
    strftime(change_time, sizeof(change_time), "%Y-%m-%d %H:%M:%S", localtime(&sb.st_ctime));

    printf("h. Time of Last Access: %s\n", access_time);
    printf("i. Time of Last Modification: %s\n", modify_time);
    printf("j. Time of Last Change: %s\n", change_time);

    return 0;
}

