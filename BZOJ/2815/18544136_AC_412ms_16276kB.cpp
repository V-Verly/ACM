#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int maxn=7e4+10;

vector<int> edge[maxn],tree[maxn],pt;
int n,indegree[maxn];

void add(int u,int v)
{
    edge[u].push_back(v);
    indegree[v]++;
}

void Toposort()
{
    queue<int> que;
    for(int i=1;i<=n;i++)
        if(!indegree[i]) que.push(i);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        pt.push_back(u);
        indegree[u]--;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            indegree[v]--;
            if(!indegree[v]) que.push(v);
        }
    }
}

int dep[maxn],fa[maxn][30];

void init(int u)
{
    for(int i=1;(1<<i)<=dep[u];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
}

int LCA(int u,int v)
{
    if(u==-1) return v;
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

void build()
{
    dep[0]=0;
    for(int k=pt.size()-1;k>=0;k--)
    {
        int pre=-1,u=pt[k];
        //printf("%d\n",u);
        for(int i=0;i<edge[u].size();i++)
            pre=LCA(pre,edge[u][i]);

        if(pre==-1) pre=0;

        tree[pre].push_back(u);
        dep[u]=dep[pre]+1;
        fa[u][0]=pre;
        init(u);
    }
}

int sz[maxn];

void dfs(int u)
{
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        dfs(v);
        sz[u]+=sz[v]+1;
    }
}

int main()
{
    int v;
    scanf("%d",&n);
    for(int u=1;u<=n;u++)
        while(scanf("%d",&v)!=EOF&&v) add(u,v);
    Toposort();
    build();
    dfs(0);
    for(int i=1;i<=n;i++)
        printf("%d\n",sz[i]);
    return 0;
}
