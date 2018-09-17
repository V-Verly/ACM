#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int inf=0x3f3f3f3f;

int n;
int cost[maxn][maxn],mx[maxn][maxn],mincost[maxn],pre[maxn];
bool vis[maxn],used[maxn][maxn];

int prim()
{
    for(int u=2;u<=n;u++)
        mincost[u]=cost[1][u],vis[u]=false,pre[u]=1;
    int res=0;
    mincost[1]=0;
    pre[1]=0;
    vis[1]=true;
    for(int q=2;q<=n;q++)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) return -1;
        res+=mincost[v];
        vis[v]=true;
        used[v][pre[v]]=used[pre[v]][v]=true;
        for(int u=1;u<=n;u++)
        {
            if(vis[u]) mx[u][v]=mx[v][u]=max(mx[u][pre[v]],mincost[v]);
            if(!vis[u]&&mincost[u]>cost[v][u])
            {
                mincost[u]=cost[v][u];
                pre[u]=v;
            }
        }
    }
    return res;
}

int smst(int min_ans)
{
    int ans=inf;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(cost[i][j]!=inf&&!used[i][j])
                ans=min(ans,min_ans+cost[i][j]-mx[i][j]);
    if(ans==min_ans) return -1;
    return ans;
}

int main()
{
    int t,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        memset(cost,inf,sizeof(cost));
        memset(used,false,sizeof(used));
        memset(mx,0,sizeof(mx));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=w;
        }
        int ans=prim();
        if(ans==-1) printf("Not Unique!\n");
        else
        {
            int tmp=smst(ans);
            if(tmp==-1) printf("Not Unique!\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
