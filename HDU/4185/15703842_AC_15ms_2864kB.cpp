#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=600+10;
char a[610][610];
int id[610][610];

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
    int n,t;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        memset(edge,0,sizeof(edge));
        cnt=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]=='#') id[i][j]=++cnt;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='#')
                {
                    if(i-1>=0&&a[i-1][j]=='#') edge[id[i][j]][id[i-1][j]]=1;
                    if(j-1>=0&&a[i][j-1]=='#') edge[id[i][j]][id[i][j-1]]=1;
                    if(i+1<n&&a[i+1][j]=='#') edge[id[i][j]][id[i+1][j]]=1;
                    if(j+1<n&&a[i][j+1]=='#') edge[id[i][j]][id[i][j+1]]=1;
                }
            }
        }
        printf("Case %d: %d\n",_,hungary()/2);
    }
    return 0;
}
