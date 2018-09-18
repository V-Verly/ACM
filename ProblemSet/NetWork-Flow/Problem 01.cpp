/**
网络流24题: 1.飞行员配对方案问题
模型：二分图最大匹配
**/

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=150;

int m,n;
int edge[maxn][maxn];
int linker[maxn],match[maxn];
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
                match[u]=v;
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
    memset(match,0xff,sizeof(match));
    for(int i=1;i<=m;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int u,v;
    scanf("%d%d",&m,&n);
    memset(edge,0,sizeof edge);
    while(scanf("%d%d",&u,&v)&&(u+v)!=-2)
        edge[u][v]=1;
    int res=hungary();
    if(res)
    {
        printf("%d\n",res);
        for(int i=1;i<=m;i++) if(~match[i]) printf("%d %d\n",i,match[i]);
        return 0;
    }
    printf("No Solution!\n");
    return 0;
}