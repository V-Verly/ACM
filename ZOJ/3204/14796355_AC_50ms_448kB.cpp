#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=200;
const int inf=0x3f3f3f3f;

int n,tot;
int cost[maxn][maxn],mincost[maxn],pre[maxn];
bool vis[maxn];

struct edge
{
    int u,v;
}ans[maxn];

bool cmp(const edge& a,const edge& b)
{
    if(a.u==b.u) return a.v<b.v;
    return a.u<b.u;
}

bool prim()
{
    for(int i=1;i<n;i++)
        mincost[i]=cost[0][i],vis[i]=false,pre[i]=0;
    mincost[0]=inf;
    vis[0]=true;
    for(int i=1;i<n;i++)
    {
        int v=-1,minc=inf;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(mincost[u]<minc||mincost[u]==minc&&pre[u]<v))
            {
                minc=mincost[u];
                v=u;
            }
        if(minc==inf) return false;
        if(pre[v]<v)
            ans[tot].u=pre[v],ans[tot++].v=v;
        else
            ans[tot].u=v,ans[tot++].v=pre[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
        {
            if(!vis[u]&&(cost[v][u]<mincost[u]||mincost[u]==cost[v][u]&&v<pre[u]))
            {
                mincost[u]=cost[v][u];
                pre[u]=v;
            }
        }
    }
    return true;
}

int main()
{
    int t,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&w);
                cost[i][j]=cost[j][i]=w?w:inf;
            }
        }
        tot=0;
        if(prim())
        {
            sort(ans,ans+tot,cmp);
            for(int i=0;i<tot;i++)
            {
                if(i) printf(" ");
                printf("%d %d",ans[i].u+1,ans[i].v+1);
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
