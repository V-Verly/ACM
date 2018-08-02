#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=1e5+10;

int n,head[maxn],fa[maxn][30],dep[maxn],dis[maxn],cnt;

struct Edge
{
    int nex,to,w;
}edge[maxn];

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void dfs(int u,int pre)
{
    fa[u][0]=pre;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        dep[v]=dep[u]+1;
        dis[v]=dis[u]+edge[i].w;
        dfs(v,u);
    }
}

void init()
{
    for(int i=1;i<20;i++)
        for(int u=1;u<=n;u++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
}

int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;i<20;i++)
        if((1<<i)&d) u=fa[u][i];
    if(u==v) return u;
    for(int i=19;i>=0;i--)
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
    int m,u,v,w,k;
    char s[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,0xff,sizeof(head));
        memset(dep,0,sizeof(dep));
        memset(fa,0xff,sizeof(fa));
        memset(dis,0,sizeof(dis));
        cnt=0;
        while(m--)
        {
            scanf("%d%d%d%s",&u,&v,&w,s);
            add(u,v,w);
            add(v,u,w);
        }
        dfs(1,1);
        init();
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d",&u,&v);
            int root=LCA(u,v);
            printf("%d\n",dis[u]+dis[v]-2*dis[LCA(u,v)]);
        }
    }
    return 0;
}
