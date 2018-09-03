#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e5+10;

int head[maxn],pre[maxn],ans[maxn],cnt=0;
bool vis[maxn]={false};

vector<int> query[maxn];
int cf[maxn]={0};

struct Edge
{
    int nex,to,no;
}edge[2*maxn];

void add(int u,int v,int no)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].no=no;
    head[u]=cnt++;
}

int Find(int x){return x==pre[x]?x:pre[x]=Find(pre[x]); }

void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b) pre[b]=a;
}

void Tarjan(int u,int fa)
{
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        Tarjan(v,u);
        Union(u,v);
        vis[v]=true;
    }
    for(int i=0;i<query[u].size();i++)
    {
        int e=query[u][i];
        if(vis[e])
        {
            int root=Find(e);
            cf[root]-=2;
            cf[e]+=1;
            cf[u]+=1;
        }
    }
}

int dfs(int u,int fa)
{
    int res=0;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        cf[u]+=dfs(v,u);
        ans[edge[i].no]+=cf[v];
    }
    return cf[u];
}

int main()
{
    int n,u,v,k;
    scanf("%d",&n);
    memset(head,0xff,sizeof(head));
    for(int i=1;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v,i);
        add(v,u,i);
    }
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&u,&v);
        query[u].push_back(v);
        query[v].push_back(u);
    }
    Tarjan(1,0);
    dfs(1,0);
    for(int i=1;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
