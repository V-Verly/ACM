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
        mincost[i]=inf,vis[i]=false;
    mincost[1]=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int v,minc=inf;
        for(int u=1;u<=n;u++)
        {
            if(!vis[u]&&(mincost[u]<minc))
            {
                v=u;
                minc=mincost[u];
            }
        }
        if(minc==inf)
        {
            printf("-1\n");
            return;
        }
        res+=mincost[v];
        vis[v]=true;
        for(int u=1;u<=n;u++)
            if(!vis[u])mincost[u]=min(mincost[u],cost[u][v]);
    }
    printf("%d\n",res);
}

int main()
{
    int t,m,k,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        memset(cost,inf,sizeof(cost));
        scanf("%d%d%d",&n,&m,&k);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }
        int q;
        while(k--)
        {
            scanf("%d%d",&q,&u);
            q--;
            while(q--)
            {
                scanf("%d",&v);
                cost[u][v]=cost[v][u]=0;
            }
        }
        prim();
    }
    return 0;
}
