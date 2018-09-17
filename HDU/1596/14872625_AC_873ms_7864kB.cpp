#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

int n;
double s[maxn][maxn],safe[maxn];
bool vis[maxn];

double dijkstra(int u,int v)
{
    for(int i=0;i<n;i++) safe[i]=s[u][i];
    safe[u]=1;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<n;i++)
    {
        int x;
        double m=0;
        for(int y=0;y<n;y++) if(!vis[y]&&safe[y]>=m) m=safe[x=y];
        vis[x]=true;
        for(int y=0;y<n;y++) if(!vis[y]) safe[y]=max(safe[y],safe[x]*s[x][y]);
    }
    return safe[v];
}

int main()
{
    int m,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%lf",&s[i][j]);
            s[i][i]=0;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            x--;y--;
            double ans=dijkstra(x,y);
            if(ans) printf("%.3f\n",ans);
            else printf("What a pity!\n");
        }
    }
    return 0;
}
