#include<stdio.h>
#include<string.h>
int main(void)
{
    long long int n,i,c,t,s,a[10001];
    c=0;
    for(i=1;i<=10000;i++)
    {
        a[i]=i*i*i%10000;
        c+=a[i];
    }
    c%=10000;
    while(~scanf("%lld",&n))
    {
    s=0;
    t=n/10000;
    n%=10000;
    s+=t*c;
    s%=10000;
    for(i=1;i<=n;i++)
    s+=a[i];
    s%=10000;
    printf("%0*lld\n",4,s);
    }
}