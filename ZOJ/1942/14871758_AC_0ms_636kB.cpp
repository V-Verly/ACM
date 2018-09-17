#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double inf=1e12;
double w[210][210],dis[210];
int n;
bool vis[210];

void dijkstra()
{
    for(int i=0;i<n;i++) dis[i]=inf,vis[i]=false;
    dis[0]=0;
    for(int i=1;i<n;i++)
    {
        int x;
        double m=inf;
        for(int y=0;y<n;y++)
            if(!vis[y]&&dis[y]<=m) m=dis[x=y];
        vis[x]=true;
        for(int y=0;y<n;y++)
            if(!vis[y]) dis[y]=min(dis[y],max(dis[x],w[x][y]));
    }
}

int main()
{
    int x[210],y[210],kase=1;
    while(scanf("%d",&n)!=EOF&&n)
    {

        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=0;j<i;j++)
                w[i][j]=w[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            w[i][i]=inf;
        }
        dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",kase++,dis[1]);
    }
    return 0;
}
