#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1e5+10;

vector<int> edge[maxn];
int n,son[maxn],node[maxn],ans[maxn];

void dfs(int u,int fa)
{
    node[u]=1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;
        dfs(v,u);
        node[u]+=node[v];
        son[u]+=son[v]+node[v];

    }
    //son[0]=son[1];
   // int tmp=son[fa]-son[u]-node[u];
   // printf("%d\n",tmp);
  //  ans[u]=son[u];

}

void dfs1(int u,int fa)
{
    //ans[u]=son[u];
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;

        int tmp=ans[u]-son[v]-node[v];
        //printf("%d %d %d\n",u,v,tmp);
        ans[v]=tmp+son[v]+(n-node[v]);
        //printf("%d\n",ans[v]);
        dfs1(v,u);

    }
}

int main()
{
    int u,v;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear(),son[i]=ans[i]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1,0);
        ans[1]=son[1];
        dfs1(1,0);
        for(int i=1;i<=n;i++)
            printf("%d\n",ans[i]);

    }
    return 0;
}
