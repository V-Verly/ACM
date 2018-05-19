#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int dp[maxn];

int main()
{
    int n,m,i,j,need[505],val[505];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&need[i],&val[i]);
        for(i=0;i<n;i++)
            for(j=need[i];j<=m;j++)
            dp[j]=max(dp[j],dp[j-need[i]]+val[i]);
        printf("%d\n",dp[m]);
    }
    return 0;
}
