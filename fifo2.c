#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define FIFO1_NAME "Server_fifo"
#define FIFO2_NAME "Client_fifo"
int main()
{
char p[100],f[100],c[300];
int num,num2,f1,fd,fd2;
mknod(FIFO1_NAME,S_IFIFO | 0666,0);
mknod(FIFO2_NAME,S_IFIFO | 0666,0);
printf("\n waiting for server...\n");
fd=open(FIFO1_NAME,O_WRONLY);
printf("\n server online!\nclient:enter the path\n");
while(gets(p) , !feof(stdin))
{
if((num=write(fd,p,strlen(p)))==-1)
perror("write error\n");
else
{
printf("\n waiting for reply....\n");
fd2=open(FIFO2_NAME,O_RDONLY);
if((num2=read(fd2,c,300))==-1)
perror("transfer error!\n");
else
{
printf("file received!displaying the contents:\n");
if(fputs(c,stdout)==EOF)
perror("print error");
exit(1);
}
}
}