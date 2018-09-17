#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;

int n;
int cost[maxn][maxn],dis[maxn];
bool vis[maxn];

void dijkstra(int s)
{
    for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=false;
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        int x,m=inf;
        for(int y=1;y<=n;y++) if(!vis[y]&&dis[y]<=m) m=dis[x=y];
        vis[x]=1;
        for(int y=1;y<=n;y++) if(!vis[y]) dis[y]=min(dis[y],dis[x]+cost[x][y]);
    }
}

int main()
{
    int m,s,u,v,w,t;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        memset(cost,inf,sizeof(cost));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[v][u]=min(cost[v][u],w);
        }
        dijkstra(s);
        int ans=inf;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&u);
            ans=min(ans,dis[u]);
        }
        printf("%d\n",ans>=inf?-1:ans);
    }
    return 0;
}
