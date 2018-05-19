#include<stdio.h>

int main()
{
    int n,k,i,t=0,a[105];
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    if(k%a[i]==0&&a[i]>t) t=a[i];
    t=k/t;
    printf("%d\n",t);
    return 0;
}
