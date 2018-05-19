#include <stdio.h>
int main(void)
{
    int a[1005],b[1005];
    int i,n;
    a[0]=1,b[0]=1;
    for(i=1;i<=1000;i++)
    {
        a[i]=a[i-1]+i;
        b[i]=b[i-1]+a[i-1];
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",b[n]);
    }
    return 0;
}
