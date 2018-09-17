#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,c[505],dp[505][505]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int k=1;k<n;k++)
    {
        for(int l=1;l+k<=n;l++)
        {
            int r=l+k;
            dp[l][r]=k+1;
            if(c[l]==c[r])
            {
                dp[l][r]=dp[l+1][r-1];
                if(k==1) dp[l][r]++;
            }
            for(int m=l;m<r;m++)
                dp[l][r]=min(dp[l][r],dp[l][m]+dp[m+1][r]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
