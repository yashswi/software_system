
#include<unistd.h>
#include<stdio.h>
#include<fcbtl.h>

int main(void)
{
	int fd;
	char buf[100];
	fd= open("newfile",O_WRONLY);
	printf("Enter the text: ");
	scanf("%[^\n}",buf);
        write(fd,buf,sizeof(buf));
	printf("%s\n",buf);

}
