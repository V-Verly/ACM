#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=150;

int n;
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
    for(int i=0;i<n;i++)
    {
            memset(vis,false,sizeof(vis));
            res+=path(i);
    }
    return res;
}

int main()
{
    int a[105][105],res[1005][2],cnt;
    while(scanf("%d",&n)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]) edge[i][j]=1;
            }
        }
        if(hungary()!=n) printf("-1\n");
        else
        {
            cnt=0;
            for(int i=0;i<n;i++)
            {
                if(linker[i]!=i)
                {
                    res[cnt][0]=i;
                    res[cnt++][1]=linker[i];
                    for(int j=0;j<n;j++)
                    {
                        if(linker[j]==i)
                        {
                            swap(linker[i],linker[j]);
                            break;
                        }
                    }
                }
            }
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++)
                printf("R %d %d\n",res[i][0]+1,res[i][1]+1);
        }

    }
    return 0;
}
