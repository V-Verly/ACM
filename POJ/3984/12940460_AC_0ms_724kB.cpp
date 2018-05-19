#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int a[5][5],vis[5][5];
struct point{
int x,y;
int px,py;
};
point s[5][5];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void print(int x,int y){

    if(x==0&&y==0) {
        printf("(%d, %d)\n",x,y);
        return;
    }
    print(s[x][y].px,s[x][y].py);
    printf("(%d, %d)\n",x,y);
}
void BFS(int x,int y)
{
    vis[x][y]=1;
    queue <point> que;
    point t;
    t.x=x;
    t.y=y;
    t.px=0;
    t.py=0;
    que.push(t);
    while(!que.empty())
    {
        point k=que.front();
        que.pop();
        if(k.x==4&&k.y==4) {print(4,4);break;}
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i];
            int fy=k.y+dy[i];
            if(fx>=0&&fx<5&&fy>=0&&fy<5&&!vis[fx][fy]&&!a[fx][fy])
            {
                vis[fx][fy]=1;
                point tmp;
                s[fx][fy].x=fx;
                s[fx][fy].y=fy;
                s[fx][fy].px=k.x;
                s[fx][fy].py=k.y;
                que.push(s[fx][fy]);
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&a[0][0])!=EOF)
    {
        for(i=1;i<5;i++)
            scanf("%d",&a[0][i]);
        for(i=1;i<5;i++)
            for(j=0;j<5;j++)
            scanf("%d",&a[i][j]);
        memset(vis,0,sizeof(vis));
        BFS(0,0);
    }
    return 0;
}
