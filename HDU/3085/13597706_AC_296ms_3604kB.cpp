#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int m,n;
char a[805][805];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
int mx,my,gx,gy,zx[2],zy[2],step;
bool vis[2][805][805];
struct Node {int x,y;};

inline bool Manhattan(Node t)
{
    return (abs(t.x-zx[0])+abs(t.y-zy[0])>2*step)&&(abs(t.x-zx[1])+abs(t.y-zy[1])>2*step);
}

queue <Node> q[2];

bool BFS(int r)
{
    Node k;
    int count=q[r].size();
    while(count--)
    {
        k=q[r].front();
        q[r].pop();
        if(Manhattan(k))
        {
            for(int i=0; i<4; i++)
            {
                Node t;
                t.x=k.x+dx[i];
                t.y=k.y+dy[i];

                if(t.x>=0&&t.x<n&&t.y>=0&&t.y<m&&a[t.x][t.y]!='X'&&Manhattan(t)&&!vis[r][t.x][t.y])
                {
                    vis[r][t.x][t.y]=true;
                    if(vis[0][t.x][t.y]&&vis[1][t.x][t.y])
                        return true;
                    q[r].push(t);
                }
            }
        }
    }
    return false;
}

int solve()
{
    while(!q[0].empty())  q[0].pop();
    while(!q[1].empty())  q[1].pop();
    Node k;
    k.x=mx;
    k.y=my;
    q[0].push(k);
    k.x=gx;
    k.y=gy;
    q[1].push(k);
    step=0;
    while(!(q[0].empty()&&q[1].empty()))
    {
        step++;
        for(int i=0; i<3; i++)
            if(BFS(0))  return step;
        if(BFS(1))  return step;
    }
    return -1;
}

int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%s",a[i]);
        k=0;
        memset(vis,false,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]=='M')
                {
                    mx=i;
                    my=j;
                    vis[0][i][j]=true;
                }
                else if(a[i][j]=='G')
                {
                    gx=i;
                    gy=j;
                    vis[1][i][j]=true;
                }
                else if(a[i][j]=='Z')
                {
                    zx[k]=i;
                    zy[k++]=j;
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
