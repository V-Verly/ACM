#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn=1e5+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn],father[maxn],pre[maxn];
int bridge,n;

int Find(int x){return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int u,int v)
{
    int a=Find(u),b=Find(v);
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
            if(low[v]>dfn[u])
                bridge++;
            else Union(u,v);
        }
        else if(v!=fa)
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
    int m,q,u,v,cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            pre[i]=i;
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        memset(dfn,0,sizeof(dfn));
        bridge=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(1,0,1);
        scanf("%d",&q);
        printf("Case %d:\n",++cnt);
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
