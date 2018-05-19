#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf=1e8;
char a[205][205];
int n,m,vis[205][205][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct point{
int x,y,n;
};
int BFS(point s,point t)
{

    queue <point> que;
    que.push(s);
    que.push(t);
    vis[s.x][s.y][s.n]=vis[t.x][t.y][t.n]=1;
    int mn=inf;
    while(!que.empty())
    {
        point k=que.front();
        que.pop();
        if(a[k.x][k.y]=='@'&&vis[k.x][k.y][0]&&vis[k.x][k.y][1])
            mn=min(mn,vis[k.x][k.y][0]+vis[k.x][k.y][1]);
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i];
            int fy=k.y+dy[i];
            if(fx>=0&&fx<n&&fy>=0&&fy<m&&a[fx][fy]!='#'&&!vis[fx][fy][k.n])
            {
                vis[fx][fy][k.n]=vis[k.x][k.y][k.n]+1;
                point r;
                r.x=fx;
                r.y=fy;
                r.n=k.n;
                que.push(r);
            }
        }
    }
    return mn-2;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int mn;
        point s,t;
        for(i=0;i<n;i++)
            scanf("%s",a[i]);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            if(a[i][j]=='Y'){s.x=i;s.y=j;s.n=0;}
            else if(a[i][j]=='M') {t.x=i;t.y=j;t.n=1;}
        memset(vis,0,sizeof(vis));
        mn=BFS(s,t);
        printf("%d\n",mn*11);
    }
    return 0;
}
