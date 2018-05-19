#include <stdio.h>
int main ()
{
    int n,i,t=0,s=0,a[200005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]==2) {a[i]=0,t++;}
    }
    for(i=0;i<n&&t>0;i++)
    {
        if(a[i]==1) {a[i]=0;t--;s++;}
    }
    t=0;
    for(i=0;i<n;i++)
    t+=a[i];
    s+=t/3;
    printf("%d\n",s);
    return 0;
}
