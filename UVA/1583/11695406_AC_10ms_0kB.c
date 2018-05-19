#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,x,m,a[200005],j,t;
    memset(a,0,sizeof(a));
    for(i=100000;i>=0;i--)
    {
        x=i,m=x;
        while(x>0)
        {
            m+=x%10;
            x/=10;
        }
        
        a[m]=i;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
    printf("%d\n",a[n]);
    }
    return 0;
}