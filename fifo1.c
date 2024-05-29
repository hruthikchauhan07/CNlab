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
printf("\n server is online!!!...\n");
 fd=open(FIFO1_NAME,O_RDONLY);
 printf("\n client is online!\n");
 while(1)
{
 if((num=read(fd,p,100))==-1)
 perror("read error\n");
else
{
p[num]='\0';
if((f1=open(p,O_RDONLY))<0)
{
printf("\nserver %s is not found",p);
exit(1);
}
else
{
printf("Server %s found!\n transferring the content\n",p);
stdin=fdopen(f1,"r");
while(!feof(stdin))
{
if(fgets(c,300,stdin)!=NULL)
{
fd2=open(FIFO2_NAME,O_WRONLY);
if(num2=write(fd2,c,strlen(c))==-1)
perror("Transfer error");
}
else
perror("read");
}
printf("Server transfer completed\n");
exit(1);
}
}
}
return 1;
}