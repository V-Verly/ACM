#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
int cost[30][30],mincost[30];
bool vis[30];
int n;

int prim()
{
    for(int u=0;u<n;u++)
        mincost[u]=inf,vis[u]=0;
    int res=0;
    mincost[0]=0;
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
    int w,u,v,t;
    char s[5];
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(cost,inf,sizeof(cost));
        for(int i=1;i<n;i++)
        {
            scanf("%s%d",s,&t);
            u=s[0]-'A';
            while(t--)
            {
                scanf("%s%d",s,&w);
                int v=s[0]-'A';
                cost[u][v]=cost[v][u]=w;
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
