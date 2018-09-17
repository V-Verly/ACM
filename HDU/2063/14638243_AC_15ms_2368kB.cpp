#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int nx,ny;
bool edge[1010][1010],vis[1010];
int linker[1010];

bool path(int u)
{
    for(int v=1;v<=ny;v++)
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
    for(int i=1;i<=nx;i++)
    {
        memset(vis,0,sizeof(vis));
        res+=path(i);
    }
    return res;
}

int main()
{
    int m,u,v;
    while(scanf("%d",&m)!=EOF&&m)
    {
        scanf("%d%d",&nx,&ny);
        memset(edge,0,sizeof(edge));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=1;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
