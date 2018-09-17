#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[105][105];
bool vis[105][105];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int fx=x+dx[i],fy=y+dy[i];
        if(fx>=0&&fx<n&&fy>=0&&fy<m&&!vis[fx][fy]&&a[fx][fy]=='#')
        {
            vis[fx][fy]=true;
            bfs(fx,fy);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j]&&a[i][j]=='#')
                {
                    bfs(i,j);
                    ans++;
                }
        printf("%d\n",ans);
    }
    return 0;
}
