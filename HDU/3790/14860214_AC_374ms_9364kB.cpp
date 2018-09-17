#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;

int n;
int dis[maxn],cost[maxn],vis[maxn],mp[maxn][maxn],val[maxn][maxn];

void dijkstra(int u,int v)
{
    for(int i=1;i<=n;i++) dis[i]=cost[i]=inf;
    dis[u]=cost[u]=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        int x,m=inf,c=inf;
        for(int y=1;y<=n;y++)
        {
            if(!vis[y]&&(dis[y]<m||dis[y]==m&&cost[y]<=c))
            {
                m=dis[y];
                c=cost[y];
                x=y;
            }
        }
        vis[x]=1;
        for(int y=1;y<=n;y++)
        {
            if(!vis[y]&&dis[x]+mp[x][y]<dis[y])
            {
                dis[y]=dis[x]+mp[x][y];
                cost[y]=cost[x]+val[x][y];
            }
            else if(!vis[y]&&dis[x]+mp[x][y]==dis[y]&&cost[y]>cost[x]+val[x][y])
            {
                cost[y]=cost[x]+val[x][y];
            }
        }
    }
    printf("%d %d\n",dis[v],cost[v]);
}

int main()
{
    int m,u,v,w,c;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(mp,inf,sizeof(mp));
        memset(val,inf,sizeof(val));
        while(m--)
        {
            scanf("%d%d%d%d",&u,&v,&w,&c);
            if(w<mp[u][v])
            {
                mp[u][v]=mp[v][u]=w;
                val[u][v]=val[v][u]=c;
            }
            else if(w==mp[u][v]&&val[u][v]>c)
            {
                val[u][v]=val[v][u]=c;
            }

        }
        scanf("%d%d",&u,&v);
        dijkstra(u,v);
    }
    return 0;
}
