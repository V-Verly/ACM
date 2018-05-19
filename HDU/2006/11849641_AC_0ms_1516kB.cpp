#include <stdio.h>
#include <math.h>
int main(void)
{
    long long m,n,t,i;
    while(scanf("%lld",&n)!=EOF)
    {
        t=1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&m);
            if(m%2) t*=m;
        }
        printf("%lld\n",t);
    }
    return 0;
}