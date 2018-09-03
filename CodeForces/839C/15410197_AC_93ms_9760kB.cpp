#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e5+10;
vector<int> tree[maxn];

double ans[maxn];

void dfs(int u,int fa)
{
    int s=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==fa) continue;
        s++;
        dfs(v,u);
        ans[u]+=ans[v];
    }
    if(s) ans[u]=ans[u]/s+1;
}

int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        tree[i].clear(),ans[i]=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    printf("%lf\n",ans[1]);
    return 0;
}
