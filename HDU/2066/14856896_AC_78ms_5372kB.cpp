#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int mp[maxn][maxn],dis[maxn],vis[maxn];

void dijkstra()
{
    for(int i=0;i<maxn;i++) dis[i]=inf;
    dis[0]=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<maxn;i++)
    {
        int x,m=inf;
        for(int y=0;y<maxn;y++) if(!vis[y]&&dis[y]<=m) m=dis[x=y];
        vis[x]=1;
        for(int y=0;y<maxn;y++) dis[y]=min(dis[y],dis[x]+mp[x][y]);
    }
}

int main()
{
    int t,s,d,u,v,w;
    while(scanf("%d%d%d",&t,&s,&d)!=EOF)
    {
        memset(mp,inf,sizeof(mp));
        while(t--)
        {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=mp[v][u]=min(mp[u][v],w);
        }
        while(s--)
        {
            scanf("%d",&u);
            mp[0][u]=mp[u][0]=0;
        }
        dijkstra();
        int ans=inf;
        while(d--)
        {
            scanf("%d",&u);
            ans=min(ans,dis[u]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
