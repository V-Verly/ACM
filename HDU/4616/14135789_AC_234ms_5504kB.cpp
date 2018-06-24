#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=5e4+10;
int N,c,ans,val[maxn],trap[maxn];
int dp[maxn][4][2];
vector<int> tree[maxn];

void dfs(int u,int pre)
{
    dp[u][trap[u]][trap[u]]=val[u];
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==pre) continue;
        dfs(v,u);
        for(int j=0;j<=c;j++)
        {
            for(int k=0;k+j<=c;k++)
            {
                ans=max(ans,dp[u][j][1]+dp[v][k][1]);
                if(j+k<c) ans=max(ans,dp[u][j][0]+dp[v][k][0]);
                if(j!=c) ans=max(ans,dp[u][j][0]+dp[v][k][1]);
                if(k!=c) ans=max(ans,dp[u][j][1]+dp[v][k][0]);
            }
        }
        for(int j=0;j+trap[u]<=c;j++)
        {
            dp[u][j+trap[u]][0]=max(dp[u][j+trap[u]][0],dp[v][j][0]+val[u]);
            if(j) dp[u][j+trap[u]][1]=max(dp[u][j+trap[u]][1],dp[v][j][1]+val[u]);
        }
    }
}

int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&c);
        for(int i=0;i<N;i++)
            tree[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
            scanf("%d%d",&val[i],&trap[i]);
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ans=0;
        dfs(0,-1);
        printf("%d\n",ans);
    }
    return 0;
}
