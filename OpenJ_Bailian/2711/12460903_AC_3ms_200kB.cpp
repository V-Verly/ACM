#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int x,int y){
return x>y?x:y;
}
int main()
{
    int a[105],dpu[105],dpd[105],n,i,j,mx;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            dpu[i]=1;
            dpd[i]=1;
        }
        for(i=1;i<n;i++)
            for(j=0;j<i;j++)
                if(a[i]>a[j])
                dpu[i]=max(dpu[i],dpu[j]+1);
        for(i=n-1;i>=0;i--)
            for(j=n-1;j>i;j--)
                if(a[i]>a[j])
                dpd[i]=max(dpd[i],dpd[j]+1);
        mx=0;
        for(i=0;i<n;i++){
            mx=max(dpd[i]+dpu[i]-1,mx);
        }

        printf("%d\n",n-mx);
    }
    return 0;
}
