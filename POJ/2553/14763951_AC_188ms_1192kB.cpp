#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=5000+10;

vector<int> edge[maxn];

int dfn[maxn],low[maxn],sccno[maxn],degree[maxn];
int stack[maxn],index,tot,scc;
bool instack[maxn];

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

int main()
{
    int n,m,u,v;
    bool ans[maxn];
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(degree,0,sizeof(degree));
        tot=index=scc=0;
        for(u=1;u<=n;u++)
            if(!dfn[u]) Tarjan(u);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(sccno[v]!=sccno[u])
                    degree[sccno[u]]++;
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=scc;i++)
        {
            if(!degree[i])
            {
                for(u=1;u<=n;u++)
                    if(sccno[u]==i) ans[u]=true;
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(ans[i])
            {
                if(count++) printf(" ");
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
