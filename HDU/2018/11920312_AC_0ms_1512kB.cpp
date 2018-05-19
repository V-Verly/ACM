#include <stdio.h>
int main(void)
{
    int m,n,a[56],i; 
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
    a[1]=1,a[2]=2;a[3]=3,a[4]=4;
    for(i=5;i<56;i++)
    a[i]=a[i-1]+a[i-3];
printf("%d\n",a[n]);
        }
    return 0;
}