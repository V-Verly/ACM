#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e4+10;
vector <int> edge[maxn];

int dfn[maxn],low[maxn];
int stack[maxn],ind,tot;
bool vis[maxn];
int belong[maxn],degree[maxn],scc;

void Tarjan(int v)
{
    dfn[v]=low[v]=++tot;
    stack[++ind]=v;
    vis[v]=true;
    int u;
    for(int i=0;i<edge[v].size();i++)
    {
        u=edge[v][i];
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
        do
        {
            u=stack[ind--];
            vis[u]=false;
            belong[u]=scc;
        }while(u!=v);
    }
}

int main()
{
    int n,m,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));
        ind=tot=scc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        memset(degree,0,sizeof(degree));
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(belong[v]!=belong[u])
                    degree[belong[u]]++;
            }
        }
        int ans=0,cnt;
        for(int i=1;i<=scc;i++)
            if(!degree[i]) cnt=i,ans++;
        if(ans==1)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
                if(belong[i]==cnt) sum++;
            printf("%d\n",sum);
        }
        else
            printf("0\n");
    }
    return 0;
}