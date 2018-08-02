#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=5000+10;

vector <int> edge[maxn];

int dfn[maxn],low[maxn],tot;
int stack[maxn],index;
int degree[maxn],sccno[maxn],scc;
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
        do
        {
            v=stack[index--];
            instack[v]=false;
            sccno[v]=scc;
        }while(v!=u);
        scc++;
    }
}

int main()
{
    int n,m,u,v;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(instack,0,sizeof(instack));
        memset(degree,0,sizeof(degree));
        index=tot=scc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(sccno[v]!=sccno[u])
                    degree[sccno[u]]++;
            }
        }
        bool ans[maxn]={false};
        for(int i=0;i<scc;i++)
        {
            if(!degree[i])
            {
                for(u=1;u<=n;u++)
                    if(sccno[u]==i) ans[u]=true;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(ans[i])
            {
                if(cnt++) printf(" ");
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
