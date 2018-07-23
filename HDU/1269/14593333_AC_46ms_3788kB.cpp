#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e4+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn];
int stack[maxn],tot,index,sum=0;
bool vis[maxn];

void tarjan(int v)
{
    dfn[v]=low[v]=++tot;
    stack[++index]=v;
    vis[v]=true;
    for(int i=0;i<edge[v].size();i++)
    {
        int u=edge[v][i];
        if(!dfn[u])
        {
            tarjan(u);
            low[v]=min(low[v],low[u]);
        }
        else if(vis[u])
            low[v]=min(low[v],dfn[u]);
    }
    if(low[v]==dfn[v])
    {
        int u=0;
        do
        {
            u=stack[index];
            vis[u]=false;
            index--;
        }while(u!=v);
        sum++;
    }
}

int main()
{
    int m,n,u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        sum=0,index=0,tot=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) tarjan(i);
        printf("%s\n",sum==1?"Yes":"No");
    }

    return 0;
}