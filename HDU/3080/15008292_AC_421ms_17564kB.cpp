#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2000+10;
const int inf=0x3f3f3f3f;

int ln,pn,dn;
int cost[maxn][maxn],mincost[maxn];
bool vis[maxn];

void prim()
{
    int n=ln+pn,st;
    for(st=0;st<n;st++)
        if(!vis[st]) break;
    memset(mincost,inf,sizeof(mincost));
    for(int i=0;i<n;i++)
        if(!vis[st]) mincost[i]=cost[st][i];
    mincost[st]=0;
    int res=0;
    for(int i=0;i<n-dn;i++)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1||mincost[v]==inf)
        {
            printf("what a pity!\n");
            return;
        }
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            if(!vis[u]) mincost[u]=min(mincost[u],cost[u][v]);
    }
    printf("%d\n",res);
}

int main()
{
    int t,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&ln,&m);
        memset(cost,inf,sizeof(cost));
        memset(vis,false,sizeof(vis));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }
        scanf("%d%d",&pn,&m);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }
        scanf("%d",&dn);
        for(int i=0;i<dn;i++)
        {
            scanf("%d",&u);
            vis[u]=true;
        }
        prim();
    }
    return 0;
}
