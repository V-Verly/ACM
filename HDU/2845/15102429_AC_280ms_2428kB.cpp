#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;

int n,m;
int a[maxn];

int dp[maxn],f[maxn];

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m*n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
            f[0]=0;
            f[1]=a[i*m];
            for(int j=2;j<=m;j++)
                f[j]=max(f[j-2]+a[i*m+j-1],f[j-1]);
            dp[i+1]=f[m];
        }
        dp[0]=0;
        for(int i=2;i<=n;i++)
            dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
        printf("%d\n",dp[n]);
    }
    return 0;
}
