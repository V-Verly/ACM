#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int r,c,h[105][105],dp[105][105];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    int ans,mx=0;
    for(int i=0;i<4;i++)
    {
        int fx=dx[i]+x,fy=dy[i]+y;
        if(fx>=0&&fx<r&&fy>=0&&fy<c&&h[fx][fy]<h[x][y])
        {
            ans=dfs(fx,fy);
            mx=max(mx,ans);
        }
    }
    dp[x][y]=mx+1;
    return dp[x][y];
}

int main()
{
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&h[i][j]);
        int ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                ans=max(ans,dfs(i,j));
        printf("%d\n",ans);
    }
    return 0;
}
