#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn=1e5+10;

int n,pre[maxn],depth[maxn],father[maxn],dp[maxn][20],bridge;
int dfn[maxn],low[maxn];

vector<int> edge[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a==b) return false;
    pre[b]=a;
    return true;
}

void Tarjan(int u,int fa,int dep)
{
    dfn[u]=low[u]=dep;
    father[u]=fa;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(!dfn[v])
        {
            Tarjan(v,u,dep+1);
            low[u]=min(low[u],low[v]);
        }
        else if(fa!=v)
            low[u]=min(low[u],dfn[v]);
    }
}

void LCA(int u,int v)
{
    if(dfn[u]<dfn[v]) swap(u,v);
    while(dfn[u]>dfn[v])
    {
        if(Union(u,father[u])) bridge--;
        u=father[u];
    }
    while(u!=v)
    {
        if(Union(u,father[u])) bridge--;
        if(Union(v,father[v])) bridge--;
        u=father[u];
        v=father[v];
    }
}

int main()
{
    int m,u,v,q,kase=1;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=1;i<=n;i++) pre[i]=i,edge[i].clear();
        memset(dfn,0,sizeof(dfn));
        memset(depth,0,sizeof(depth));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        Tarjan(1,0,1);
        bridge=0;
        for(int i=1;i<=n;i++)
        {
            u=father[i];
            if(u==0) continue;
            if(low[i]>dfn[u]) bridge++;
            else Union(u,i);
        }
        scanf("%d",&q);
        printf("Case %d:\n",kase++);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            LCA(u,v);
            printf("%d\n",bridge);
        }
        printf("\n");
    }
    return 0;
}
