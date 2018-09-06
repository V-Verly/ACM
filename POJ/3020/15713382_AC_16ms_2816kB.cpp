#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=750;

int cnt;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];

bool path(int u)
{
    for(int v=1;v<=cnt;v++)
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
    for(int i=1;i<=cnt;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int t,n,m;
    int id[45][15];
    char a[45][15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]=='*')
                    id[i][j]=++cnt;
        memset(edge,0,sizeof(edge));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='*')
                {
                    if(i>0&&a[i-1][j]=='*') edge[id[i][j]][id[i-1][j]]=1;
                    if(j>0&&a[i][j-1]=='*') edge[id[i][j]][id[i][j-1]]=1;
                    if(i<n-1&&a[i+1][j]=='*') edge[id[i][j]][id[i+1][j]]=1;
                    if(j<n-1&&a[i][j+1]=='*') edge[id[i][j]][id[i][j+1]]=1;
                }
            }
        printf("%d\n",(cnt*2-hungary())/2);
    }
    return 0;
}
