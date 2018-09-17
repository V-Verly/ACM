#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=505;
const int inf=0x3f3f3f3f;
int n;
int cost[maxn][maxn],mincost[maxn];
bool vis[maxn];

int prim()
{
    for(int u=0;u<n;u++)
        mincost[u]=inf,vis[u]=0;
    int res=0;
    mincost[0]=0;
    for(;;)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    return res;
}

int main()
{
    int t,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(cost,inf,sizeof(cost));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=w;
        }
        printf("%d\n",prim());
    }
    return 0;
}
