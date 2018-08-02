#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=40000+10;

struct Edge{int nex,to,w;}edge[maxn];
int n,head[maxn],cnt;

int dep[maxn],fa[maxn][17],dis[maxn];
bool vis[maxn];

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    fa[u][0]=pre;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v!=pre) dfs(v,u);
        dis[u]+=dis[v]+edge[i].w;
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
    if(dep[u]<dep[v])
        swap(u,v);
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

int main()
{
    int t,m,u,v,w,root,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            dis[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            vis[v]=true;
        }
        for(int i=1;i<=n;i++)
            if(!vis[i]) root=i;
        dfs(root,0);
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            root=LCA(u,v);
            ans=dis[root]-dis[u]+dis[root]-dis[v];
            printf("%d\n",ans);
        }
    }
    return 0;
}
