#include <stdio.h>
#include <math.h>
int main(void)
{
    
    long long m,n,i,t,x,y;
    while(scanf("%lld%lld",&m,&n)!=EOF)
    {
        x=0,y=0;
        if(m>n) t=m,m=n,n=t;
       for(i=m;i<=n;i++)
       {
           if(i%2==0) x+=i*i;
           else y+=i*i*i;
       }
       printf("%lld %lld\n",x,y);
    }
    return 0;
}