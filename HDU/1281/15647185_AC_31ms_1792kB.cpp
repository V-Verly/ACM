#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int a[10010],b[10010];
int edge[105][105];
int linker[105];
bool vis[105];

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
    int k,cnt=0;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            edge[a[i]][b[i]]=1;
        }
        int ans=hungary(),res=0;
        for(int i=0;i<k;i++)
        {
            edge[a[i]][b[i]]=0;
            int tmp=hungary();
            if(ans>tmp) res++;
            edge[a[i]][b[i]]=1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",++cnt,res,ans);
    }
    return 0;
}
