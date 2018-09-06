#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=210;

int n;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];
int color[maxn];

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

bool dfs(int u)
{
    bool flag=true;
    for(int v=1;v<=n;v++)
    {
        if(!edge[u][v]) continue;
        if(color[v]==-1)
        {
            color[v]=!color[u];
            flag&=dfs(v);
        }
        else if(color[v]==color[u]) return false;
    }
    return flag;
}

int main()
{
    int m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        memset(color,0xff,sizeof(color));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=edge[v][u]=1;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(!dfs(i))
                {
                    flag=false;
                    break;
                }
            }
        }
        if(!flag) printf("No\n");
        else printf("%d\n",hungary()/2);
    }
    return 0;
}
