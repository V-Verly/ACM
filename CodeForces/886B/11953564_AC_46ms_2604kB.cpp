#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,i,t,l,a[200200];
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[t]=i;
    }
    l=0;
    while(a[l]==-1) l++;
    for(i=l;i<200200;i++)
    {
        if(a[i]!=-1&&a[l]>a[i]) l=i;
    }
    printf("%d\n",l);
    return 0;
}