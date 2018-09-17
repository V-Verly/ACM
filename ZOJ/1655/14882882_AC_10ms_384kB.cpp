#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100+10;

int n,val[maxn];
double cost[maxn][maxn],d[maxn];
bool vis[maxn];

double dijkstra()
{
    for(int i=1;i<=n;i++) d[i]=cost[n][i],vis[i]=false;
    d[n]=0;
    for(int i=1;i<n;i++)
    {
        int x=0;
        double m=0;
        for(int y=1;y<=n;y++) if(!vis[y]&&d[y]>m) m=d[x=y];
        vis[x]=true;
        for(int y=1;y<=n;y++) if(!vis[y]) d[y]=max(d[y],d[x]*cost[x][y]);
    }
    double ans=0;
    for(int i=1;i<n;i++)
        ans+=val[i]*d[i];
    return ans;
}

int main()
{
    int m,u,v;
    double w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<n;i++)
            scanf("%d",&val[i]);
        memset(cost,0,sizeof(cost));
        while(m--)
        {
            scanf("%d%d%lf",&u,&v,&w);
            cost[u][v]=cost[v][u]=max(cost[u][v],1-w);
        }
        printf("%.2lf\n",dijkstra());
    }
    return 0;
}