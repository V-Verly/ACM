#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1e5+10;

int n,num[maxn]={0};
long long dp[maxn]={0};
vector <int> edge[maxn];

void dfs(int u,int fa,long long len)
{
    num[u]=1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;
        dfs(v,u,len+1);
        num[u]+=num[v];
    }
    dp[1]+=len;
}

void dfs1(int u,int fa)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;
        dp[v]=dp[u]+(n-num[v])-num[v];
        dfs1(v,u);
    }
}

int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0,0);
    dfs1(1,0);
    for(int i=1;i<=n;i++) printf("%lld\n",dp[i]);
    return 0;
}
