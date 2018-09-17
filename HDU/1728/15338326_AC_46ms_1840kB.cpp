#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char a[105][105];
int vis[105][105];
int m,n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Node
{
    int x,y,step,face;
    bool operator<(const Node &t) const
    {
        return step>t.step;
    }
};

bool check(int x,int y,int step)
{
    return x>=0&&x<m&&y>=0&&y<n&&vis[x][y]>=step&&a[x][y]=='.';
}

void BFS(int sx,int sy,int ex,int ey,int step)
{
    Node st{sx,sy,-1,-1};
    priority_queue<Node> que;
    que.push(st);
    vis[sx][sy]=0;
    while(!que.empty())
    {
        Node k=que.top();
        que.pop();
        if(k.step>step) break;
       // printf("%d %d %d\n",k.x,k.y,k.step);
        if(k.x==ex&&k.y==ey&&k.step<=step)
        {
            printf("yes\n");
            //else printf("no\n");
            return;
        }
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i],fy=k.y+dy[i];
            if(check(fx,fy,k.step+(i!=k.face)))
            {
                //if(k.x==0&&k.y==1)
                    //printf("%d %d %d\n",fx,fy,k.step+(i!=k.face));
                vis[fx][fy]=k.step+(i!=k.face);
                que.push({fx,fy,k.step+(i!=k.face),i});
            }
        }
    }
    printf("no\n");
}

int main()
{
    int t,sx,sy,ex,ey,step;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",a[i]);
        scanf("%d%d%d%d%d",&step,&sy,&sx,&ey,&ex);
        memset(vis,0x3f3f3f3f,sizeof(vis));
        BFS(sx-1,sy-1,ex-1,ey-1,step);
    }
    return 0;
}
