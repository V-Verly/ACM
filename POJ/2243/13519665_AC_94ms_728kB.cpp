#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int sx,sy,ex,ey;
char st[5],en[5];
int dx[8]={-2,-1,1,2,-2,-1,1,2};
int dy[8]={-1,-2,-2,-1,1,2,2,1};
bool vis[10][10];

struct point{
int x,y,step;
};

const int inf=0x3f3f3f3f;

int BFS()
{
    point a;
    a.x=sx,a.y=sy,a.step=0;
    vis[sx][sy]=true;
    queue <point> que;
    que.push(a);
    while(!que.empty())
    {
        point k=que.front();
        que.pop();
        if(k.x==ex&&k.y==ey)
        {
            printf("To get from %s to %s takes %d knight moves.\n",st,en,k.step);
            break;
        }
        int ans=inf;
        for(int i=0;i<8;i++)
        {
            int fx=k.x+dx[i];
            int fy=k.y+dy[i];
            if(fx>=0&&fx<8&&fy>=0&&fy<8&&!vis[fx][fy])
            {
                vis[fx][fy]=true;
                    point r;
                    r.x=fx,r.y=fy,r.step=k.step+1;
                    que.push(r);
            }
        }
    }
}

int main()
{
    while(scanf("%s%s",st,en)!=EOF)
    {
        sx=st[0]-'a';
        sy=st[1]-'1';
        ex=en[0]-'a';
        ey=en[1]-'1';
        memset(vis,false,sizeof(vis));
        BFS();
    }
    return 0;
}
