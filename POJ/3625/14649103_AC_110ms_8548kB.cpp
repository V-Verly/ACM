#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double inf=1e12;

int n;
double cost[1005][1005],mincost[1005];
bool vis[1005];

double prim()
{
    for(int i=0;i<=n;i++)
        mincost[i]=inf,vis[i]=0;
    double res=0;
    mincost[1]=0;
    for(;;)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        vis[v]=true;
        res+=mincost[v];
        for(int u=1;u<=n;u++)
            mincost[u]=min(mincost[u],cost[u][v]);
    }
    return res;
}

int main()
{
    int m,u,v;
    double x[1005],y[1005];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            for(int j=1;j<i;j++)
                cost[i][j]=cost[j][i]=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
            cost[i][i]=inf;
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            cost[u][v]=cost[v][u]=0;
        }
        printf("%.2f\n",prim());
    }
    return 0;
}
