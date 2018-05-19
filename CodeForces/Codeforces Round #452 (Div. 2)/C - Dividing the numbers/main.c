#include <stdio.h>
int main ()
{
    int n,i,t;
    scanf("%d",&n);
    if(n%4==0)
    {
        printf("0\n");
        printf("%d ",n/2);
        for(i=1;i<=n/4;i++)
        printf("%d ",i);
        for(i=0;i<n/4;i++)
        printf("%d ",n-i);
    }
    if(n%4==3)
    {
        printf("0\n");
        printf("%d ",(n-3)/2+2);
        printf("1 2 ");
        for(i=4;i<4+n/4;i++)
        printf("%d ",i);
        for(i=0;i<n/4;i++)
        printf("%d ",n-i);
    }
    if(n%4==1)
    {
        printf("1\n");
        printf("%d ",(n-1)/2+1);
        printf("1 ");
        for(i=0;i<n/4;i++)
        printf("%d ",i+2);
        for(i=0;i<n/4;i++)
        printf("%d ",n-i);
    }
    if(n%4==2)
    {
        printf("1\n");
        printf("%d ",(n-2)/2+1);
        printf("1 ");
        for(i=0;i<n/4;i++)
        printf("%d ",3+i);
        for(i=0;i<n/4;i++)
        printf("%d ",n-i);
    }
    return 0;
}
