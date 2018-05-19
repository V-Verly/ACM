#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long sum,c,n,i;
    double a[25],t[25];
    a[2]=1;
    a[3]=2;
    sum=1;
    for(i=4;i<=20;i++)
    {
        a[i]=(i-1)*a[i-1]+(i-1)*a[i-2];
    }
    for(i=2;i<=20;i++)
    {
        sum*=i;
        t[i]=a[i]*100/sum;
    }
    scanf("%lld",&c);
    while(c--){
        scanf("%lld",&n);
        printf("%.2f%%\n",t[n]);
    }
    return 0;
}
