#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1e5+10;

struct Edge{int nex,to; }edge[maxn<<1];

int n,head[maxn],dep[maxn],fa[maxn][30],cnt;

void add(int u,int v)
{
    edge[++cnt].nex=head[u];
    edge[cnt].to=v;
    head[u]=cnt;
}

void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    fa[u][0]=pre;
    for(int i=1;(1<<i)<=n;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nex) if(edge[i].to!=pre) dfs(edge[i].to,u);
}

int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;(1<<i)<=d;i++) if((1<<i)&d) u=fa[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

int sta[maxn];

int dfs1(int u,int pre)
{
    for(int i=head[u];i;i=edge[i].nex) if(edge[i].to!=pre) sta[u]+=dfs1(edge[i].to,u);
    return sta[u];
}

int main()
{
    int m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs(1,0);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        int root=LCA(u,v);
        sta[u]++; sta[v]++;
        sta[root]-=2;
    }
    dfs1(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(sta[i]==0&&i!=1) ans+=m;
        else if(sta[i]==1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
