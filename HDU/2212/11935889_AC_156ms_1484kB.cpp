#include<stdio.h>
int main(void)
{
  int n,i,t,s,a[10];
  a[0]=1;
  for(i=1;i<10;i++)
     a[i]=i*a[i-1];
 for(n=1;n<=a[9]*9;n++)
     {
         s=0;
         t=n;
         while(t>0)
         {
             s+=a[t%10];
             t/=10;
         }
         if(s==n) printf("%d\n",n);
     }
  return 0;
}