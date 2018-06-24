#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=2e4+10;
const int inf=0x3f3f3f3f;
int d[maxn],n,minBalance,minNode;
vector<int> tree[maxn];

void dfs(int u,int fa)
{
    d[u]=1;
    int mx=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v!=fa)
        {
            dfs(v,u);
            d[u]+=d[v];
            mx=max(mx,d[v]);
        }
    }
    mx=max(mx,n-d[u]);
    if(mx<minBalance)
    {
        minBalance=mx;
        minNode=u;
    }
}

int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=1;i<n;i++)
            tree[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        minNode=0;
        minBalance=inf;
        dfs(1,0);
        printf("%d %d\n",minNode,minBalance);
    }
    return 0;
}
