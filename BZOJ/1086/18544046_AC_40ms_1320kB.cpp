#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1000+10;

vector<int> tree[maxn];

int b,sz[maxn];
int st[maxn],top=0;
int cap[maxn],num[maxn],cnt=0;

int dfs(int u,int pre)
{
    st[++top]=u;
    sz[u]=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==pre) continue;
        dfs(v,u);
        if(sz[v]+sz[u]>=b)
        {
            sz[u]=0;
            cap[++cnt]=u;
            while(st[top]!=u) num[st[top--]]=cnt;
        }
        else sz[u]+=sz[v];
    }
    sz[u]++;
}

int main()
{
    int n,u,v;
    scanf("%d%d",&n,&b);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    while(top) num[st[top--]]=cnt;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++) printf("%d ",num[i]);
    printf("\n");
    for(int i=1;i<=cnt;i++) printf("%d ",cap[i]);
    printf("\n");
    return 0;
}
