#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=500+10;
const int inf=0x3f3f3f3f;
int n,cost[maxn][maxn],mincost[maxn];
bool vis[maxn];

void prim()
{
    for(int i=1;i<=n;i++)
        mincost[i]=cost[1][i],vis[i]=0;
    mincost[1]=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1||mincost[v]==inf)
        {
            printf("-1\n");
            return;
        }
        res+=mincost[v];
        vis[v]=true;
        for(int u=1;u<=n;u++)
            if(!vis[u]) mincost[u]=min(mincost[u],cost[u][v]);
    }
    printf("%d\n",res);
}

int main()
{
    int m,k,u,v,w,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(cost,inf,sizeof(cost));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }
        while(k--)
        {
            scanf("%d%d",&m,&u);
            m--;
            while(m--)
            {
                scanf("%d",&v);
                cost[u][v]=cost[v][u]=0;
            }
        }
        prim();
    }
    return 0;
}
