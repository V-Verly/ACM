#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;

int edge[105][105];
int mincost[105];
bool vis[105];
int V;

void prim()
{
    for(int i=1;i<=V;i++)
    {
        mincost[i]=edge[1][i];
        vis[i]=false;
    }
    mincost[1]=0;
    int res=0;

    for(;;)
    {
        int v=-1;
        for(int u=1;u<=V;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        vis[v]=true;
        res+=mincost[v];
        for(int u=1;u<=V;u++)
            mincost[u]=min(mincost[u],edge[v][u]);
    }
    printf("%d\n",res);
}

int main()
{
    int n,u,v,w;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n*(n-1)/2;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u][v]=edge[v][u]=w;
        }
        V=n;
        prim();
    }
    return 0;
}
