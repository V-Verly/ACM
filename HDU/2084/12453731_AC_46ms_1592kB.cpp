#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b){
return a>b?a:b;
}
int main()
{
    int c,n,i,j,a[105][105],dp[105][105];
    scanf("%d",&c);
    while(c--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                scanf("%d",&a[i][j]);
        for(i=n-1;i>=0;i--)
            for(j=0;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
