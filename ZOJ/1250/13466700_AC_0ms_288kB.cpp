#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,d[12][12],i,j,a[12][12][35],dp[1005][12],count=0;
    while(scanf("%d%d",&n,&k)!=EOF&&(k||n))
    {
        memset(a,0,sizeof(a));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==j)
                    continue;
                scanf("%d",&d[i][j]);
                for(int r=0; r<d[i][j]; r++)
                    scanf("%d",&a[i][j][r]);
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[0][1]=0;
        for(int r=1; r<=k; r++)
        {
            for(i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(j==i)
                        continue;
                    int cost=a[i][j][(r-1)%d[i][j]];
                    if(cost&&dp[r-1][i]!=-1)
                    {
                        if(dp[r][j]==-1)
                            dp[r][j]=dp[r-1][i]+cost;
                        else
                            dp[r][j]=min(dp[r][j],dp[r-1][i]+cost);
                    }
                }
            }
        }
        printf("Scenario #%d\n",++count);
        if(dp[k][n]!=-1)
            printf("The best flight costs %d.\n\n",dp[k][n]);
        else
            printf("No flight possible.\n\n");
    }
    return 0;
}
