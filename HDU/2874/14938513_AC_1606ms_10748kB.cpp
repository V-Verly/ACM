#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=1e5+10;

int head[maxn],dis[maxn],cnt;
int n,fa[maxn][18],pre[maxn],dep[maxn];
bool vis[maxn];

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
    vis[u]=true;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre||vis[v]) continue;
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
            if(fa[u][i-1]>0) fa[u][i]=fa[fa[u][i-1]][i-1];
        	else fa[u][i]=-1;
}

void solve()
{
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i,0);
	init();
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

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void Union(int u,int v)
{
    int a=Find(u),b=Find(v);
    if(a!=b) pre[b]=a;
}

int main()
{
    int m,c,u,v,w;
    while(scanf("%d%d%d",&n,&m,&c)!=EOF)
    {
        for(int i=0;i<=n;i++) pre[i]=i;
        memset(head,0xff,sizeof(head));
    	memset(edge,0,sizeof(edge));
        memset(fa,0xff,sizeof(fa));
        memset(dis,0,sizeof(dis));
        memset(dep,0,sizeof(dep));
        cnt=0;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
            Union(u,v);
        }
        memset(vis,0,sizeof(vis));
        solve();
        while(c--)
        {
            scanf("%d%d",&u,&v);
            if(Find(u)==Find(v))
            {
                int root=LCA(u,v);
                printf("%d\n",-dis[root]*2+dis[u]+dis[v]);
            }
            else printf("Not connected\n");
        }
    }
    return 0;
}
