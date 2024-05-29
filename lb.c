#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int t_rand(int a)
{
 int rn;
 rn=random()%10;
 rn=rn%a;
 if(rn==0)
 rn=1;
return(rn);
}
main()
{
 int i,j,clk,packets[5],o_rate,i_rate,b_size,p_remain,p_sz,p_sz_rm=0,p_time,flag=0;
system("clear");
 printf("Enter 5 packets in the stream:");
 for(i=0;i<5;++i)
{
// packets[i]=t_rand(7)*10;
 
scanf("%d",&packets[i]);
 } 
 
 printf("\nEnter the Output Rate:");
 scanf("%d",&o_rate);
 printf("\nEnter the Bucket Size:");
 scanf("%d",&b_size);
 for(i=0;i<5;++i)
 {
 if((packets[i]+p_sz_rm)>b_size)
 {
 if(packets[i]>b_size)
printf("\n\n Incoming packet size( %d )is GREATER than bucket capacity -
!!!REJECTED!!!",packets[i]);
 else
 printf("\nBucket capacity exceeded - !!!REJECTED!!!");
 }
 else
 {
 for(j=0;;++j)
 {
 p_remain=4-i;
 p_sz=packets[i];
 p_sz_rm+=p_sz;
 printf("\n\n Incoming Packet Size : %d",p_sz);
 printf("\n Transmission Left : %d",p_sz_rm);
 p_time=t_rand(5)*2;
 printf("\n\n Next Packet will come at : %d",p_time);
 for(clk=0;clk<p_time;clk+=1)
 {
 printf("\n Time left : %d",clk);
 sleep(1);
 if(p_sz_rm)
 {
 printf(" - !!!Transmitted!!!");
 if(p_sz_rm<=o_rate)
 p_sz_rm=0;
 else
 p_sz_rm-=o_rate;
 printf(" - Bytes Remaining : %d",p_sz_rm);
 }
 else
 printf(" - No Packets to transmit!!!");
 }
 if(p_sz_rm!=0)
 flag=1;
 break;
 }
 }
 }
 printf("\n\n");
 return(0);
}