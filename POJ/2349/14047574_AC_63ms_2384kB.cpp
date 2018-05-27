#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=500+10;
const double inf=1e12;
struct point{double x,y; }p[maxn];
double cost[maxn][maxn];
double mincost[maxn];
bool used[maxn];
int m,n;

double dis(const point &a,const point &b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

void prim()
{
    for(int i=0;i<m;i++)
        mincost[i]=cost[i][0],used[i]=false;
    mincost[0]=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<m;u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<m;u++)
            if(!used[u]) mincost[u]=min(mincost[u],cost[v][u]);
    }
    sort(mincost,mincost+m);
    printf("%.2f\n",mincost[m-n]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
                cost[i][j]=cost[j][i]=dis(p[i],p[j]);
            cost[i][i]=inf;
        }
        prim();
    }
}
