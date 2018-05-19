#include <stdio.h>
int main ()
{
    long long a[21],n,i;
    a[2]=1,a[3]=2;
    for(i=4;i<=20;i++)
        a[i]=(i-1)*a[i-1]+(i-1)*a[i-2];
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
