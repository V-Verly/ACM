#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int head[maxn],tot,vis[maxn],f[maxn],g[maxn],s[maxn],h[maxn];

struct node
{
    int to,nex,w;
    node(){}
    node(int a,int b,int c):to(a),nex(b),w(c){}
}edge[20*maxn];

void add(int u,int v,int w)
{
    edge[tot]=node(v,head[u],w);
    head[u]=tot++;
    edge[tot]=node(u,head[v],w);
    head[v]=tot++;
}

void dfs(int u,int fa)
{
    f[u]=0,g[u]=0,s[u]=-1;
    int k,v;
    for(int k=head[u];k!=-1;k=edge[k].nex)
    {
        v=edge[k].to;
        if(v==fa) continue;
        dfs(v,u);
        if(f[u]<=f[v]+edge[k].w)
        {
            s[u]=v;
            g[u]=f[u];
            f[u]=f[v]+edge[k].w;
        }
        if(g[u]<=f[v]+edge[k].w&&s[u]!=v) g[u]=f[v]+edge[k].w;
    }
}

void dfs1(int u,int fa)
{
    int k,v;
    for(int k=head[u];k!=-1;k=edge[k].nex)
    {
        v=edge[k].to;
        if(v==fa) continue;
        if(s[u]!=v)
            h[v]=max(h[u],f[u])+edge[k].w;
        else
            h[v]=max(h[u],g[u])+edge[k].w;
        dfs1(v,u);
    }
}

int main()
{
    int N,v,w;
    while(scanf("%d",&N)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(edge,0,sizeof(edge));
        tot=0;
        for(int u=2;u<=N;u++)
        {
            scanf("%d%d",&v,&w);
            add(u,v,w);
        }
        dfs(1,0);
        memset(h,0,sizeof(h));
        dfs1(1,0);
        h[1]=g[1];
        for(int i=1;i<=N;i++)
            printf("%d\n",max(h[i],f[i]));
    }

    return 0;
}
