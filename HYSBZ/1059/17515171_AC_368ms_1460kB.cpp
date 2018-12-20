#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=200+10;

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
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(edge,0,sizeof edge);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&x);
                if(x) edge[i][j]=1;
            }
        }
        printf("%s\n",hungary()==n?"Yes":"No");
    }
    return 0;
}
