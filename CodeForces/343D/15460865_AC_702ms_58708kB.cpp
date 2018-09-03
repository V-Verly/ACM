#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=5e5+10;
vector <int> edge[maxn];

int dfn[maxn],pre[maxn],en[maxn],cnt=0;
int val[4*maxn],lazy[4*maxn];

void dfs(int u,int fa)
{
    dfn[u]=++cnt;
    pre[u]=fa;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
    en[u]=cnt;
}

void build(int l,int r,int rt)
{
    val[rt]=0;
    lazy[rt]=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void pushdown(int rt)
{
    if(!lazy[rt]) return;
    val[rt<<1]=lazy[rt<<1]=1;
    val[rt<<1|1]=lazy[rt<<1|1]=1;
    lazy[rt]=0;
}

void Fill(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y)
    {
        val[rt]=1,lazy[rt]=1;
        return;
    }
    if(lazy[rt]) return;
    int mid=(l+r)>>1;
    if(x<=mid) Fill(l,mid,rt<<1,x,y);
    if(y>mid) Fill(mid+1,r,rt<<1|1,x,y);
    val[rt]=val[rt<<1]&val[rt<<1|1];
}

void Empty(int l,int r,int rt,int x)
{
    if(l==r)
    {
        val[rt]=0,lazy[rt]=0;
        return;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(x<=mid) Empty(l,mid,rt<<1,x);
    else Empty(mid+1,r,rt<<1|1,x);
    val[rt]=val[rt<<1]&val[rt<<1|1];
}

int query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return val[rt];
    if(lazy[rt]) return 1;
    pushdown(rt);
    int res=1;
    int mid=(l+r)>>1;
    if(x<=mid) res&=query(l,mid,rt<<1,x,y);
    if(y>mid) res&=query(mid+1,r,rt<<1|1,x,y);
    return res;
}

int main()
{
    int n,u,v,q;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&u,&v);
        if(u==1)
        {
            int tmp=query(1,n,1,dfn[v],en[v]);
            if(tmp==0&&pre[v]) Empty(1,n,1,dfn[pre[v]]);
            Fill(1,n,1,dfn[v],en[v]);
        }
        else if(u==2) Empty(1,n,1,dfn[v]);
        else printf("%d\n",query(1,n,1,dfn[v],en[v]));
    }
    return 0;
}
