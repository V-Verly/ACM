#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int k,n,a[105][105],dp[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int DFS(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    int t,mx=0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=k;j++)
        {
            int fx=x+j*dx[i];
            int fy=y+j*dy[i];
            if(fx>=0&&fx<n&&fy>=0&&fy<n&&a[x][y]<a[fx][fy])
            {
                t=DFS(fx,fy);
                mx=max(mx,t);
            }
        }
    }
    //printf("%d\n",mx);
    dp[x][y]=mx+a[x][y];
    return dp[x][y];
}

int main()

{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF&&(n!=-1||k!=-1))
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        DFS(0,0);
        printf("%d\n",dp[0][0]);
    }
    return 0;
}