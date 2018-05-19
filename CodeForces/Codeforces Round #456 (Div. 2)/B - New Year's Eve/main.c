#include<stdio.h>
int main(void)
{
    long long i,s=1,t=0;
    long long n,k;
    scanf("%lld%lld",&n,&k);
   if(k==1) t=n;
   else{
   for(i=1;i<61&&s<=n;i++)
    s*=2;
    s/=2;
    t^=s;
    t^=(s-1);
    }
    printf("%lld\n",t);
    return 0;
}
