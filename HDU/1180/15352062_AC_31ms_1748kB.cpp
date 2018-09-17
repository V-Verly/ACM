#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char a[25][25];
int vis[25][25];
int n,m,sx,sy,ex,ey;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Node
{
    int x,y,step;
    bool operator <(const Node &t) const
    {
        return step>t.step;
    }
};

bool check(int x,int y,int step)
{
    return x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='*'&&(vis[x][y]==0||vis[x][y]>step);
}

void BFS()
{
    memset(vis,0,sizeof(vis));
    priority_queue<Node> que;
    que.push({sx,sy,0});
    vis[sx][sy]=1;
    while(!que.empty())
    {
        Node k=que.top();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i],fy=k.y+dy[i],step=k.step+1;
            if(!check(fx,fy,step)) continue;
            if(a[fx][fy]=='|')
            {
                fx+=dx[i],fy+=dy[i];
                if(i%2&&!k.step%2) step++;
                if(!i%2&&k.step%2) step++;
            }
            else if(a[fx][fy]=='-')
            {
                fx+=dx[i],fy+=dy[i];
                if(i%2&&k.step%2) step++;
                if(!i%2&&!k.step%2) step++;
            }
            if(!check(fx,fy,step)) continue;
            if(fx==ex&&fy==ey)
            {
                printf("%d\n",step);
                return ;
            }
            que.push({fx,fy,step});
            vis[fx][fy]=step;
        }
    }
    printf("%d\n",0);
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]=='S') sx=i,sy=j;
                else if(a[i][j]=='T') ex=i,ey=j;
        BFS();
    }
    return 0;
}
