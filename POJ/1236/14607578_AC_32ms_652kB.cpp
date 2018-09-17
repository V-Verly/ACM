#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> edge[105];

int dfn[105],low[105];
int stack[105],index,tot;
bool vis[105];
int belong[105],scc;

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
    if(dfn[v]==low[v])
    {
        scc++;
        int u;
        do
        {

            u=stack[index];
            vis[u]=false;
            belong[u]=scc;
            index--;
        }while(u!=v);
    }
}

int main()
{
    int n,inde[105],outde[105];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        for(int u=1;u<=n;u++)
        {
            int v;
            while(scanf("%d",&v)!=EOF&&v)
                edge[u].push_back(v);
            inde[u]=outde[u]=0;
        }
        memset(vis,false,sizeof(vis));
        memset(dfn,0,sizeof(dfn));
        tot=scc=index=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(int u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                int v=edge[u][i];
                if(belong[v]!=belong[u])
                {
                    inde[belong[v]]++;
                    outde[belong[u]]++;
                }
            }
        }
        int a=0,b=0;
        for(int i=1;i<=scc;i++)
        {
            if(!inde[i]) a++;
            if(!outde[i]) b++;
        }
        int ans=max(a,b);
        if(scc==1)
            printf("1\n0\n");
        else
            printf("%d\n%d\n",a,ans);
    }
    return 0;
}
