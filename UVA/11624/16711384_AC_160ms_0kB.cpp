#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=1000+10;

char a[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn],r,c;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Node {
    int x,y,dis;
};

bool check(int x,int y)
{
    return x>=0&&x<r&&y>=0&&y<c&&a[x][y]!='#'&&(!vis[x][y]);
}

queue<Node> q;

void bfs()
{
    memset(vis,0,sizeof vis);

    while(!q.empty())
    {
        Node f=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int fx=f.x+dx[i],fy=f.y+dy[i],d=f.dis+1;
            if(check(fx,fy))
            {
                q.push({fx,fy,d});
                dis[fx][fy]=d;
                vis[fx][fy]=1;
            }
        }
    }
}

int solve(int x,int y)
{
    memset(vis,0,sizeof vis);
    queue<Node> que;
    que.push({x,y,0});
    vis[x][y]=true;
    while(!que.empty())
    {
        Node f=que.front();
        que.pop();
        if(f.x==0||f.x==r-1||f.y==0||f.y==c-1) return f.dis;
        for(int i=0;i<4;i++)
        {
            int fx=f.x+dx[i],fy=f.y+dy[i],t=f.dis+1;
            if(check(fx,fy)&&dis[fx][fy]>t)
            {
                que.push({fx,fy,t});
                vis[fx][fy]=1;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++)
            scanf("%s",a[i]);
        while(!q.empty()) q.pop();
        memset(dis,0x3f,sizeof dis);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(a[i][j]=='F') { q.push({i,j,0}); dis[i][j]=0; vis[i][j]=true; }
        bfs();
        int flag;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(a[i][j]=='J') flag=solve(i,j);
        if(~flag) printf("%d\n",flag+1);
        else printf("IMPOSSIBLE\n");

    }
    return 0;
}
