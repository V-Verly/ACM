#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double inf=1e12;
int n,p,q;
double cost[55][55];
double mincost[55];
bool vis[55];

int prim()
{
    for(int i=1;i<=n;i++)
        mincost[i]=inf,vis[i]=false;
    double res=cost[p][q];
    cost[p][q]=cost[q][p]=0;
    mincost[1]=0;
    for(;;)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        vis[v]=true;
        for(int u=1;u<=n;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    printf("%.2f\n",res);
}

int main()
{
    int x[55],y[55];
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d%d",&p,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=1;j<i;j++)
                cost[i][j]=cost[j][i]=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
            cost[i][i]=inf;
        }
        prim();
    }
    return 0;
}
