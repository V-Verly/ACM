#include <bits/stdc++.h>

using namespace std;

int a[105][105],dp[105][105],b[105][105],c[105][105];


int main()
{
    int t,n,m;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        dp[0][0]=a[0][0];
        for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+a[i][0];
        for(int j=1;j<m;j++)
        {
            b[0][j]=dp[0][j-1]+a[0][j];
            for(int i=1;i<n;i++)
                b[i][j]=max(dp[i][j-1],b[i-1][j])+a[i][j];
            c[n-1][j]=dp[n-1][j-1]+a[n-1][j];
            for(int i=n-2;i>=0;i--)
                c[i][j]=max(dp[i][j-1],c[i+1][j])+a[i][j];
            for(int i=0;i<n;i++)
                dp[i][j]=max(b[i][j],c[i][j]);
        }
        printf("Case #%d:\n%d\n",_,dp[0][m-1]);
    }
    return 0;
}
