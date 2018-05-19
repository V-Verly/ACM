#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long a[50];
    int i,n,m;
    a[0]=0,a[1]=0,a[2]=1,a[3]=2;
    for(i=4;i<42;i++)
        a[i]=a[i-1]+a[i-2];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%lld\n",a[m]);
    }
    return 0;
}

