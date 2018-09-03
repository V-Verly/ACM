#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char mp[1010][1010];
int n,m,vis[1010][1010]={false};

int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};

void bfs(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int fx=dx[i]+x,fy=dy[i]+y;
        if(fx>=0&&fx<n&&fy>=0&&fy<m&&mp[fx][fy]=='@'&&!vis[fx][fy])
        {
            vis[fx][fy]=true;
            mp[fx][fy]='.';
            bfs(fx,fy);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='@')
            {
                bfs(i,j);
                ans++;
            }
    printf("%d\n",ans);
    return 0;
}
