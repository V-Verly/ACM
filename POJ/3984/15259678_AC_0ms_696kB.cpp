#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int mp[5][5];
bool vis[5][5];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct Node
{
    int x,y,prex,prey;
}node[5][5];

void BFS()
{
    Node st{0,0,0,0};
    queue<Node> que;
    que.push(st);
    memset(vis,0,sizeof(vis));
    vis[0][0]=true;
    while(!que.empty())
    {
        Node k=que.front();
        que.pop();
        int x=k.x,y=k.y;
        if(x==4&&y==4)
        {
            int path[30][2];
            int cnt=0,px,py;
            //printf("%d %d\n",node[4][4].x,node[4][4].y);
            while(x||y)
            {
                path[cnt][0]=x,path[cnt++][1]=y;
                px=x,py=y;
                x=node[px][py].prex,y=node[px][py].prey;
            }
            path[cnt][0]=path[cnt][1]=0;
            for(int i=cnt;i>=0;i--)
                printf("(%d, %d)\n",path[i][0],path[i][1]);
        }
        for(int i=0;i<4;i++)
        {
            int fx=x+dx[i],fy=y+dy[i];

            if(fx>=0&&fx<5&&fy>=0&&fy<5&&!vis[fx][fy]&&!mp[fx][fy])
            {
                vis[fx][fy]=true;
                node[fx][fy].prex=x;
                node[fx][fy].prey=y;
                que.push(Node{fx,fy,x,y});
            }
        }
    }
}

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&mp[i][j]);
    BFS();
    return 0;
}
