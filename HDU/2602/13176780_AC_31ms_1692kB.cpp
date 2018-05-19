#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long t,m,n,i,j,need[1005],val[1005],dp[1005];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0;i<n;i++)
            scanf("%lld",&val[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&need[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            for(j=m;j>=need[i];j--)
                dp[j]=max(dp[j],dp[j-need[i]]+val[i]);
        printf("%lld\n",dp[m]);
    }
    return 0;
}
