#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, " %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *abc= argv[1];
    struct stat fs;

    if (stat(abc, &fs) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (S_ISREG(fs.st_mode)) {
        printf("%s is a regular file.\n", abc);
    } else if (S_ISDIR(fs.st_mode)) {
        printf("%s is a directory.\n", abc);
    } else if (S_ISLNK(fs.st_mode)) {
        printf("%s is a symbolic link.\n", abc);
    } else if (S_ISCHR(fs.st_mode)) {
        printf("%s is a character device.\n", abc);
    } else if (S_ISBLK(fs.st_mode)) {
        printf("%s is a block device.\n", abc);
   
    } else {
        printf("%s is of unknown type.\n", abc);
    }

    return EXIT_SUCCESS;
}

