#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1000+10;

vector<int> tree[maxn];
vector<int> query[maxn];

int pre[maxn],ans[maxn];
bool vis[maxn],fa[maxn];

int Find(int x) {return x==pre[x]?x:Find(pre[x]); }

void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b) pre[b]=a;
}

void Tarjan(int u)
{
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        Tarjan(v);
        Union(u,v);
        vis[v]=true;
    }
    for(int i=0;i<query[u].size();i++)
    {
        int e=query[u][i];
        if(vis[e])
            ans[Find(e)]++;
    }
}

int main()
{
    int n,t,u,v,q,root;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            tree[i].clear();
            query[i].clear();
            fa[i]=vis[i]=false;
            ans[i]=0,pre[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d:(%d)",&u,&t);
            while(t--)
            {
                scanf("%d",&v);
                tree[u].push_back(v);
                fa[v]=true;
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf(" (%d%d)",&u,&v);
            query[u].push_back(v);
            query[v].push_back(u);
        }
         for(int i=1;i<=n;i++)
            if(!fa[i]) root=i;
        Tarjan(root);
        for(int i=1;i<=n;i++)
            if(ans[i]) printf("%d:%d\n",i,ans[i]);
    }
    return 0;
}
