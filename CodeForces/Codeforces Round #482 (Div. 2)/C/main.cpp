#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=3*1e5+10;
long long sz[maxn],pre[maxn];
vector <int> h[maxn];

void dfs(int fa,int u)
{
    sz[u]=1,pre[u]=fa;
    for(int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if(v!=fa) dfs(u,v),sz[u]+=sz[v];
    }
}

int main()
{
    int n,x,y,u,v;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dfs(0,x);
    int tmp=y;
    while(pre[tmp]!=x) tmp=pre[tmp];
    long long ans=(long long)n*(n-1)-(sz[x]-sz[tmp])*sz[y];
    printf("%lld\n",ans);
    return 0;
}
