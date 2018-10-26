#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

int head[maxn],x[maxn],cnt;
int tree[20*maxn][2],tot;
int flag[20*maxn];

struct Edge
{
    int nex,to,w;
}edge[2*maxn];

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void dfs(int u,int fa,int val)
{
    for(int i=head[u];~i;i=edge[i].nex)
    {
        Edge &e=edge[i];
        if(e.to==fa) continue;
        x[e.to]=val^e.w;
        dfs(e.to,u,val^e.w);
    }
}

void insert_ch(int x,int p)
{
    int root=0;
    for(int i=30;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(!tree[root][id]) tree[root][id]=++tot;
        root=tree[root][id];
    }
    flag[root]=p;
}

int find_ch(int x)
{
    int root=0;
    for(int i=30;i>=0;i--)
    {
        int id=!((x>>i)&1);
        if(!tree[root][id]) root=tree[root][!id];
        else root=tree[root][id];
    }
    return flag[root];
}

void init()
{
    memset(tree,0,sizeof tree);
    memset(flag,0,sizeof flag);
    tot=0;
}

int main()
{
    int n,u,v,w;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,0xff,sizeof head);
        cnt=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dfs(0,-1,0);
        init();
        insert_ch(x[0],0);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int t=find_ch(x[i]);
            if((x[i]^x[t])>ans) ans=(x[i]^x[t]);
            insert_ch(x[i],i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
