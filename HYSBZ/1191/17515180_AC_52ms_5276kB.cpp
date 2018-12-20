#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1000+10;

int n,m;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];

bool path(int u)
{
    for(int v=0;v<n;v++)
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
    for(int i=0;i<m;i++)
    {
            memset(vis,false,sizeof(vis));
            if(path(i)) res++;
            else return res;
    }
    return res;
}

int main()
{
    int a,b;
    scanf("%d%d",&n,&m);
    memset(edge,0,sizeof edge);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        edge[i][a]=edge[i][b]=1;
    }
    printf("%d\n",hungary());
    return 0;
}
