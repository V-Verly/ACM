#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=10000+10;

vector <int> tree[maxn];
int x,y,pre[maxn];
bool vis[maxn],fa[maxn];

int Find(int x) {return x==pre[x]?x:Find(pre[x]); }

void Union(int u,int v)
{
    int a=Find(u),b=Find(v);
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
    if(u==x&&vis[y]) printf("%d\n",Find(y));
    if(u==y&&vis[x]) printf("%d\n",Find(x));
}

int main()
{
    int t,N,u,v,root;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            vis[i]=fa[i]=0,pre[i]=i;
            tree[i].clear();
        }
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            fa[v]=true;
        }
        scanf("%d%d",&x,&y);
        for(int i=1;i<=N;i++)
            if(!fa[i]) root=i;
        Tarjan(root);
    }
    return 0;
}
