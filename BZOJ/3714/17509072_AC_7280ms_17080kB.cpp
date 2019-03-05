#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn=2000+10;
const int inf=0x3f3f3f3f;

int cost[maxn][maxn],mincost[maxn];
bool vis[maxn];

ll prim(int n)
{
    memset(mincost,inf,sizeof mincost);
    memset(vis,0,sizeof vis);
    mincost[0]=0;
    ll res=0;
    for(;;)
    {
        int v=-1;
        for(int u=0;u<=n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<=n;u++)
            if(!vis[u]&&mincost[u]>cost[u][v]) mincost[u]=min(cost[u][v],mincost[u]);
    }
    return res;
}

int main()
{
    int n,w;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cost[i][i]=inf;
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&w);
            cost[i][j]=cost[j][i]=w;
        }
    }
    cost[n][n]=inf;
    printf("%lld\n",prim(n));
    return 0;
}
