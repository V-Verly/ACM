#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=100+10;
const int inf= 0xfffffff;
double cost[maxn][maxn];
double mincost[maxn];
bool used[maxn];
int V;

void prim()
{
    for(int i=0;i<V;i++)
    {
        mincost[i]=inf;
        used[i]=false;
    }
    mincost[0]=0;
    double res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        if(mincost[v]==inf)
        {
            printf("oh!\n");
            return;
        }
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    printf("%.1f\n",res*100);
    return;
}


int main()
{
    int t,c,x[105],y[105];
    scanf("%d",&t);
    while(t--)
    {
        memset(cost,0,sizeof(cost));
        scanf("%d",&c);
        V=c;
        for(int i=0;i<c;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=0;j<i;j++)
            {
                double l=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                if(l>=10&&l<=1000) cost[i][j]=cost[j][i]=l;
                else cost[i][j]=cost[j][i]=inf;
            }
        }
        prim();
    }
    return 0;
}