#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=500+10;

int p;
int edge[maxn][maxn];
int linker[maxn];
bool vis[maxn];

bool path(int u)
{
    for(int v=1;v<=p;v++)
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
    for(int i=1;i<=p;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int n,m;
    char like[510][20],hate[510][20];
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        for(int i=1;i<=p;i++)
        {
            scanf("%s%s",like[i],hate[i]);
        }
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=p;j++)
            {
                if(i==j) continue;
                if(strcmp(like[i],hate[j])==0) edge[i][j]=1;
                if(strcmp(like[j],hate[i])==0) edge[i][j]=1;
            }
        }
        printf("%d\n",(2*p-hungary())/2);
    }
    return 0;
}
