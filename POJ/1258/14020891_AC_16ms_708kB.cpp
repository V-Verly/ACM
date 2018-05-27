#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int inf=0x3f3f3f3f;
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int V;

int prim()
{
    for(int i=0;i<V;i++)
    {
        mincost[i]=inf;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;

    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
        {
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}

int main()
{
    while(scanf("%d",&V)!=EOF)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                scanf("%d",&cost[i][j]);
        }
        printf("%d\n",prim());
    }
}
