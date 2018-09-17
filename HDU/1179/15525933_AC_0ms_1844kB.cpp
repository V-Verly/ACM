#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=350;

int n,m;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];

bool path(int u)
{
    for(int v=1;v<=m;v++)
    {
        if(edge[u][v]&&!vis[v])
        {
            vis[v]=true;
            if(linker[v]==-1||path(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res=0;
    memset(linker,0xff,sizeof(linker));
    for(int i=1;i<=n;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int s,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&s);
            while(s--)
            {
                scanf("%d",&v);
                edge[i][v]=1;
            }
        }
        printf("%d\n",hungary());
    }
    return 0;
}
