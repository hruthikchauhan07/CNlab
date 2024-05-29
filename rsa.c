#include<stdio.h>
#include<math.h>
double min(double x, double y)
{
 return(x<y?x:y);
}
 
double max(double x, double y)
{
 return(x>y ? x:y);
}
 
double gcd(double x, double y)
{
 if(x==y)
 return (x);
 else
 return(gcd(min(x,y),max(x,y)-min(x,y)));
}
 
 
long double modexp(long double a,long double x,long double n)
{
 long double r=1;
 while(x>0)
 {
 if((int)(fmodl(x,2))==1)
 {
 r=fmodl((r*a),n);
 }
 a=fmodl((a*a),n);
 x/=2;
 }
 return(r);
}
 
main()
{
 long double p,q,phi,n,e,d, ms,es,ds;
 system("clear");
 do{
 printf("\nEnter prime numbers P and Q : ");
 scanf("%Lf %Lf",&p,&q);
 }while(p==q);
 n=p*q;
 phi=(p-1)*(q-1);
 do{
 printf("\nEnter prime value of e : ");
 scanf("%Lf",&e);
 }while((gcd(e,phi)!=1) && e>phi);
 for(d=1;d<phi;++d)
 {
 if(fmod((e*d),phi)==1)
 break;
 }
 printf("\nD within main = %Lf",d);
 printf("\nEnter the message : ");
 scanf("%Lf",&ms);
 es=modexp(ms,e,n);
 ds=modexp(es,d,n);
 printf("\nOriginal message : %Lf",ms);
 printf("\nEncrypted message : %Lf",es);
 printf("\nDecrypted message : %Lf\n\n",ds);
 return(0);
}