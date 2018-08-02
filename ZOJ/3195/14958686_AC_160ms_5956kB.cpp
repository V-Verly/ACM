#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=5e4+10;
int n,head[maxn],cnt;
int fa[maxn][20],dep[maxn],dis[maxn];

struct Edge{int nex,to,w; }edge[2*maxn];

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void dfs(int u,int pre)
{
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dis[v]=dis[u]+edge[i].w;
        dfs(v,u);
    }
}

void init()
{
    for(int i=1;(1<<i)<=n;i++)
        for(int u=1;u<=n;u++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
}

int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;(1<<i)<=d;i++)
        if((1<<i)&d) u=fa[u][i];
    if(u==v) return u;
    for(int i=(int)log(n);i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

int solve(int a,int b,int c)
{
    int root1=LCA(a,b),root2=LCA(root1,c);
    return dis[a]+dis[b]+dis[c]-dis[root1]-2*dis[root2];
}

int main()
{
    int u,v,w,q,a,b,c,ans,kase=0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,0xff,sizeof(head));cnt=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dep[0]=dis[0]=0;
        dfs(0,-1);
        init();
        scanf("%d",&q);
        if(kase++) printf("\n");
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            ans=min(solve(a,b,c),solve(b,c,a));
            ans=min(ans,solve(a,c,b));
            printf("%d\n",ans);
        }
    }
    return 0;
}
