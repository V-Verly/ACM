#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,t,i,s,a[9];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        i=0;
        while(n>0)
        {
            a[i++]=n%2;
            n/=2;
        }
        t=i;
        for(i=0;i<t;i++)
        if(a[i]==1) break;
        t=i;
        s=1;
        for(i=0;i<t;i++)
        s*=2;
        printf("%d\n",s);
    }
}