
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr , " %s <filename>\n", argv[0]);
		return 1;
	}

	const char *abc = argv[1];
	int fd = open(abc,O_RDONLY);

	if(fd==-1)
	{
		perror("Error in opening the file");
		return 1;
	}
	int flags = fcntl(fd, F_GETFL);
	
	if(flags ==-1)
	{
		perror("fnctl");
		close(fd);
		return 1;
	}
	if(flags & O_RDONLY)
	{
	 printf("File %s is opened in RO mode.\n", abc);
    }
    if (flags & O_WRONLY) {
        printf("File %s is opened in wo mode.\n", abc);
    }
    if (flags & O_RDWR) {
        printf("File %s is opened in rw mode.\n", abc);
    }

    close(fd);

    return EXIT_SUCCESS;
}
