
#include<unistd.h>
#include<stdio.h>
#include<fcbtl.h>

int main(void)
{
	char buf[100] ;
        int readcnt;
         readcnt= read(0,buf,sizeof(buf));

         write(1,buf, readcnt);

         close(0);
         close(1);

         return 0;


}
