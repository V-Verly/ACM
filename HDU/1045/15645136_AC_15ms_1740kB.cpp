#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int edge[20][20],a,b;
int linker[20];
bool vis[20];

bool path(int u)
{
    for(int v=1;v<=b;v++)
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
    for(int i=1;i<=a;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int n;
    char mp[5][5];
    int mark[5][5];
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        a=1,b=1;
        int s=0;
        memset(edge,0,sizeof(edge));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]=='X')
                {
                    if(s) a++;
                    s=0;
                    continue;
                }
                mark[i][j]=a;
                s++;
            }
            if(s) a++;
            s=0;
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(mp[i][j]=='X')
                {
                    if(s) b++;
                    s=0;
                    continue;
                }
                edge[mark[i][j]][b]=1;
                s++;
            }
            if(s) b++;
            s=0;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
