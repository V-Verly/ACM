#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1000+10;

int n,cost[maxn][maxn],way[maxn],dis[maxn];
bool vis[maxn];

void SPFA()
{
    for(int i=1;i<=n;i++)
        dis[i]=inf,vis[i]=false;
    dis[2]=0,vis[2]=true;
    queue <int> que;
    que.push(2);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        vis[v]=false;
        for(int i=1;i<=n;i++)
        {
            if(cost[v][i]<inf)
            {
                if(dis[i]>dis[v]+cost[v][i])
                {
                    dis[i]=dis[v]+cost[v][i];
                    if(!vis[i]) que.push(i),vis[i]=true;
                }
            }
        }
    }
}

int dfs(int u)
{
    if(way[u]) return way[u];
    for(int v=1;v<=n;v++)
    {
        if(cost[u][v]<inf&&dis[u]>dis[v])
            way[u]+=dfs(v);
    }
    return way[u];
}

int main()
{
    int m,u,v,w;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&m);
        memset(cost,inf,sizeof(cost));
        memset(way,0,sizeof(way));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }
        SPFA();
        way[2]=1;
        printf("%d\n",dfs(1));
    }
    return 0;
}
