#include <stdio.h>
int main(void)
{
    int m,n,i,k,t,a[105];
    while(scanf("%d%d",&n,&m)!=EOF&&(m!=0||n!=0))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            if(m<a[i]) {t=i;break;}
        if(i==n) t=n;
        for(i=n;i>t;i--)
        a[i]=a[i-1];
        a[t]=m;
        n++;
        for(i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}