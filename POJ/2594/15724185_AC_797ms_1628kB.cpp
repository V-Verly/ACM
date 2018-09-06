#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn=500+10;

int n;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];

bool path(int u)
{
    for(int v=1;v<=n;v++)
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
    int m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(edge,0,sizeof(edge));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=1;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(edge[i][k]&&edge[k][j]) edge[i][j]=1;
        printf("%d\n",n-hungary());
    }
    return 0;
}
