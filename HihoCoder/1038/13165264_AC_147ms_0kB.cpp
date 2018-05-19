#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int dp[maxn];

int main()
{
    int n,m,i,j,ans,need[505],val[505];
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&need[i],&val[i]);
    for(i=0;i<=m;i++)
        dp[i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=need[i];j--)
        {
            dp[j]=max(dp[j],dp[j-need[i]]+val[i]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
