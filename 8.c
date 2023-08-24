
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>


int main()
{
	FILE *file;
	char line[100];

	file = fopen("sample.txt","r");

	if(file==NULL)
	{
		perror("Error in file");
		return 1;

	}
	while(fgets(line ,sizeof(line), file) != NULL)
       {
	       printf("%s",line);

	}
	fclose(file);
	return 0;

 }
