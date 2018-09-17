#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=6000+10;
vector<int> tree[maxn];

int N,val[maxn];
int dp[maxn],s[maxn],gs[maxn];

int dfs(int u,int fa)
{
    int v;
    for(int i=0;i<tree[u].size();i++)
    {
        v=tree[u][i];
        if(v!=fa) dfs(v,u);
        s[u]+=dp[v];
        if(fa) gs[fa]+=dp[v];
    }
    dp[u]=max(s[u],gs[u]+val[u]);
    return dp[u];
}

int main()
{
    int u,v;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=1;i<=N;i++)
            tree[i].clear();
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        memset(gs,0,sizeof(gs));
        for(int i=1;i<=N;i++)
            scanf("%d",&val[i]);
        while(scanf("%d%d",&u,&v)!=EOF&&(u||v))
        {
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        printf("%d\n",dfs(1,0));
    }
    return 0;
}
