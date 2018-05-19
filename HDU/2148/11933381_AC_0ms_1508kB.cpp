#include<stdio.h>
int main(void)
{
    int t,n,k,i,s,x[1000];
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);
        for(i=0;i<n;i++)
        if(x[i]>x[k-1]) s++;
        printf("%d\n",s);
    }
}