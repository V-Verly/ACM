#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn=5000+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn],stack[maxn],sccno[maxn];
int index,tot,scc,n;
int linker[maxn];
bool g[maxn][maxn];
bool instack[maxn],vis[maxn];

void Tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    stack[++index]=u;
    instack[u]=true;
    int v;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        scc++;
        do
        {
            v=stack[index--];
            instack[v]=false;
            sccno[v]=scc;
        }while(u!=v);
    }
}

int path(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(g[u][v]&&!vis[v])
        {
            vis[v]=true;
            if(linker[v]==-1||path(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res=0;
    memset(linker,0xff,sizeof(linker));
    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(vis));
        res+=path(i);
    }
    return res;
}

int main()
{
    int t,m,u,v;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        index=tot=scc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                Tarjan(i);
        memset(g,false,sizeof(g));
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(sccno[v]!=sccno[u])
                    g[sccno[u]][sccno[v]]=true;
            }
        }
        int ans=hungary();
        printf("%d\n",scc-ans);
    }
}
