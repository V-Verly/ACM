#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1e6+10;

int cnt[maxn],n,root=1;
long long sum[maxn];

int head[maxn],tot=0;

struct Edge
{
    int nex,to;
}edge[maxn<<1];

void add(int u,int v)
{
    edge[tot].nex=head[u];
    edge[tot].to=v;
    head[u]=tot++;
}

void dfs(int u,int pre)
{
    cnt[u]=1;
    sum[u]=0;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
        sum[u]+=sum[v]+cnt[v];
    }
}

void dfs1(int u,int pre)
{
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        sum[v]=sum[u]-cnt[v]+(n-cnt[v]);
        dfs1(v,u);
    }
}

int main()
{
    int u,v;
    scanf("%d",&n);
    memset(head,0xff,sizeof head);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    dfs1(1,0);
    for(int i=2;i<=n;i++) if(sum[i]>sum[root]) root=i;
    printf("%d\n",root);
    return 0;
}
