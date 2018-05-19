#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a,n,i,s;
    while(~scanf("%lld",&n))
    {
        s=1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            if(a%2==1) s*=a;
        }
        printf("%lld\n",s);
    }
    return 0;
}
