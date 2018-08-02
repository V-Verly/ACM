#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,cost[45],val[45];

int dp[100010];

int cal(int m)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int w=cost[i];w<=m;w++)
            dp[w]=max(dp[w-cost[i]]+val[i],dp[w]);
    return dp[m];
}

int main()
{
    int w,t,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&w,&p);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&cost[i],&val[i]);
            cost[i]/=1000;
        }
        for(int k=1;k<=p;k++)
        {
            int tmp=w/1000;
            w+=cal(tmp);
        }

        printf("%d\n",w);
    }
    return 0;
}
