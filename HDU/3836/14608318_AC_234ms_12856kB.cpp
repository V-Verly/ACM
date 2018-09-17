#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=2e5+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn];
int stack[maxn],index,tot;
int belong[maxn],inde[maxn],outde[maxn],scc;
bool vis[maxn];

void Tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    stack[++index]=u;
    vis[u]=true;
    int v;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(vis[v])
            low[u]=min(low[v],dfn[u]);
    }
    if(dfn[u]==low[u])
    {
        scc++;
        do
        {
            v=stack[index--];
            vis[v]=false;
            belong[v]=scc;
        }while(v!=u);
    }
}

int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));
        memset(inde,0,sizeof(inde));
        memset(outde,0,sizeof(outde));
        index=tot=scc=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(belong[v]!=belong[u])
                {
                    inde[belong[v]]++;
                    outde[belong[u]]++;
                }
            }
        }
        int a=0,b=0,ans;
        for(int i=1;i<=scc;i++)
        {
            if(!inde[i]) a++;
            if(!outde[i]) b++;
        }
        ans=max(a,b);
        if(scc==1) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}
