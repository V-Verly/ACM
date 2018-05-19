#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int dp[maxn][maxn];

int main()
{
    int n,l,r,t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&dp[i][i]);
    for(int k=1;k<n;k++)
        for(int i=1;i+k<=n;i++)
            dp[i][i+k]=dp[i][i+k-1]^dp[i+1][i+k];
    for(int k=1;k<=n;k++)
        for(int i=1;i+k<=n;i++)
        dp[i][i+k]=max(max(dp[i+1][i+k],dp[i][i+k]),dp[i][i+k-1]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",dp[l][r]);
    }
    return 0;
}
