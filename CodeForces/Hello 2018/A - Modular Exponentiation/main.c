#include<stdio.h>

int main()
{
   long long m,n,flag=1;
   long long i,t,s=2;
   scanf("%lld%lld",&n,&m);
   for(i=1;i<n;i++)
   {
       s*=2;
       if(s>m) {flag=0;break;}
   }
   if(flag) m%=s;
   printf("%lld\n",m);
   return 0;
}
