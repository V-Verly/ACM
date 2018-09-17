#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
const double inf=1e12;
double cost[105][105],mincost[105];
bool vis[105];

struct Cell
{
    double x,y,z,r;
    void Set(double a,double b,double c,double d){x=a,y=b,z=c,r=d; }
};

double tangent(Cell &a,Cell &b)
{
    double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    if(len<=a.r+b.r) return 0;
    return len-a.r-b.r;
}

void prim()
{
    for(int i=0;i<n;i++)
        mincost[i]=cost[i][0],vis[i]=false;
    mincost[0]=0;
    double res=0;
    for(int i=0;i<n;i++)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            if(!vis[u]) mincost[u]=min(mincost[u],cost[u][v]);
    }
    printf("%.3f\n",res);
}

int main()
{
    Cell cell[105];
    double x,y,z,r;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x,&y,&z,&r);
            cell[i].Set(x,y,z,r);
            for(int j=0;j<i;j++)
                cost[i][j]=cost[j][i]=tangent(cell[i],cell[j]);
            cost[i][i]=inf;
        }
        prim();
    }
    return 0;
}

