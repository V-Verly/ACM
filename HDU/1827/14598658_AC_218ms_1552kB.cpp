#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1000+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn],cost[maxn],belong[maxn],degree[maxn];
int stack[maxn],index,tot,ssc;
bool vis[maxn];

void Tarjan(int v)
{
    dfn[v]=low[v]=++tot;
    stack[++index]=v;
    vis[v]=true;
    for(int i=0;i<edge[v].size();i++)
    {
        int u=edge[v][i];
        if(!dfn[u])
        {
            Tarjan(u);
            low[v]=min(low[v],low[u]);
        }
        else if(vis[u])
            low[v]=min(low[v],dfn[u]);
    }

    if(low[v]==dfn[v])
    {
        int u;
        belong[v]=++ssc;
        do
        {
            u=stack[index];
            vis[u]=false;
            belong[u]=ssc;
            index--;
        }while(u!=v);
    }
}

int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&cost[i]);
            edge[i].clear();
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(degree,0,sizeof(degree));
        tot=index=ssc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        int ans=0,sum=0;
        for(int v=1;v<=n;v++)
        {
            for(int j=0;j<edge[v].size();j++)
            {
                int u=edge[v][j];
                if(belong[v]!=belong[u])
                    degree[belong[u]]++;
            }
        }
        for(int i=1;i<=ssc;i++)
        {
            if(!degree[i])
            {
                ans++;
                int mincost=0x3f3f3f3f;
                for(int j=1;j<=n;j++)
                {
                    if(belong[j]==i)
                        mincost=min(mincost,cost[j]);
                }
                sum+=mincost;
            }
        }
        printf("%d %d\n",ans,sum);
    }
    return 0;
}
