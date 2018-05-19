#include <stdio.h>
int main ()
{
    long long a[41],n,i;
    a[1]=3,a[2]=8;
    for(i=3;i<=40;i++)
        a[i]=2*(a[i-1]+a[i-2]);
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
