#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=110;
const double inf=1e12;

int n;
double cost[maxn][maxn],mincost[maxn];
bool vis[maxn];

double prim()
{
    for(int i=0;i<n;i++)
        mincost[i]=inf,vis[i]=0;
    mincost[0]=0;
    double res=0;
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
    double x[maxn],y[maxn];
    int cnt=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            for(int j=0;j<i;j++)
                cost[i][j]=cost[j][i]=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
            cost[i][i]=inf;
        }
        if(cnt++) printf("\n");
        printf("Case #%d:\nThe minimal distance is: %.2f\n",cnt,prim());
    }
    return 0;
}
