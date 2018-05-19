#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int x,int y){
return x>y?x:y;
}
int main()
{
    int i,j,n,a[1005],b[1005],x;
    while(scanf("%d",&n)!=EOF&&n){
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        x=0;
        b[0]=a[0];
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
                if(a[j]<a[i])
                b[i]=max(b[i],b[j]+a[i]);
            b[i]=max(b[i],a[i]);
        }
        for(i=0;i<n;i++)
        {
            x=max(x,b[i]);
        }
            printf("%d\n",x);
    }
    return 0;
}
