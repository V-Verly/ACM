#include <stdio.h>
int main(void)
{
    long long int a[50],n,t,i,l;
    a[1]=1,a[2]=1;a[3]=2;
    for(i=4;i<50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&t,&l);
        printf("%lld\n",a[l-t+1]);
    }
    return 0;
}
