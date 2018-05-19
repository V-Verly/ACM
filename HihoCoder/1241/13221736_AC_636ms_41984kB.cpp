#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int a[maxn][maxn],t[maxn][maxn],f[maxn][maxn],dp[maxn][maxn][2];

int calTwo(int x)
{
    int ans=0;
    while(x%2==0)
    {
        x/=2;
        ans++;
    }
    return ans;
}

int calFive(int x)
{
    int ans=0;
    while(x%5==0)
    {
        x/=5;
        ans++;
    }
    return ans;
}

int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                {
                    t[i][j]=calTwo(a[i][j]);
                    f[i][j]=calFive(a[i][j]);
                }
                else
                    t[i][j]=f[i][j]=inf;
            }
        }
        memset(dp,inf,sizeof(dp));
        dp[0][1][0]=dp[0][1][1]=dp[1][0][0]=dp[1][0][1]=0;
        int t1,t2,f1,f2;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                dp[i][j][0]=min(min(dp[i-1][j][0],dp[i][j-1][0])+t[i][j],dp[i][j][0]);
                dp[i][j][1]=min(min(dp[i-1][j][1],dp[i][j-1][1])+f[i][j],dp[i][j][1]);
            }
        printf("%d\n",min(dp[n][n][0],dp[n][n][1]));
    }
    return 0;
}
