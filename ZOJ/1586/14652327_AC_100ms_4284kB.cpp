#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;

int n;
int cost[maxn][maxn],mincost[maxn],price[1010];
bool vis[maxn];

int prim()
{
    for(int i=0;i<n;i++)
        mincost[i]=inf,vis[i]=0;
    mincost[0]=0;
    int res=0;
    for(;;)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    return res;
}

int main()
{
    int t,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",&price[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&w);
                cost[i][j]=cost[j][i]=w+price[j]+price[i];
            }

            cost[i][i]=inf;
        }
        printf("%d\n",prim());
    }
    return 0;
}
