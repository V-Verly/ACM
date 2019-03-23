#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

int n,dep[maxn],fa[maxn][30];

struct Edge
{
    int nex,to;
}edge[maxn];

int head[maxn],cnt=1;

void add(int u,int v)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    head[u]=cnt++;
}

void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    fa[u][0]=pre;
    for(int i=1;(1<<i)<=n;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v!=pre) dfs(v,u);
    }
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

int dis(int u,int v)
{
    int root=LCA(u,v);
    return dep[u]+dep[v]-2*dep[root];
}

int main()
{
    int m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    int a,b,c,rt1,rt2,rt3,root,ans;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        rt1=LCA(a,b),rt2=LCA(a,c),rt3=LCA(b,c),root;
        if(rt1==rt2) root=rt3;
        else if(rt1==rt3) root=rt2;
        else if(rt2==rt3) root=rt1;
        ans=dis(a,root)+dis(b,root)+dis(c,root);
        printf("%d %d\n",root,ans);
    }
    return 0;
}
