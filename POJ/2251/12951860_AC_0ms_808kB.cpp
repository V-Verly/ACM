#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int l,r,c,sx,sy,sz,ex,ey,ez;
int dx[6]={0,1,0,-1,0,0};
int dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1};
char dungeon[35][35][35],vis[35][35][35];
struct point{
int x,y,z,step;
};
void BFS(int x,int y,int z)
{
    point a;
    a.x=x;
    a.y=y;
    a.z=z;
    a.step=0;
    vis[z][x][y]=1;
    queue <point> que;
    que.push(a);
    while(!que.empty())
    {
        point k=que.front();
        if(k.x==ex&&k.y==ey&&k.z==ez)
        {
            printf("Escaped in %d minute(s).\n",k.step);
            break;
        }
        que.pop();
        for(int i=0;i<6;i++)
        {
            int fx=k.x+dx[i];
            int fy=k.y+dy[i];
            int fz=k.z+dz[i];
            if(fx>=0&&fx<r&&fy>=0&&fy<c&&fz>=0&&fz<l&&dungeon[fz][fx][fy]!='#'&&!vis[fz][fx][fy])
            {
                vis[fz][fx][fy]=1;
                point r;
                r.x=fx;
                r.y=fy;
                r.z=fz;
                r.step=k.step+1;
                que.push(r);
            }
        }
    }
    if(que.empty()) printf("Trapped!\n");
}
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&l,&r,&c)!=EOF&&(l||r||c))
    {
        memset(dungeon,0,sizeof(dungeon));
        for(k=0;k<l;k++)
            for(i=0;i<r;i++)
                scanf("%s",dungeon[k][i]);
        for(k=0;k<l;k++)
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                if(dungeon[k][i][j]=='S')
                {
                    sx=i;
                    sy=j;
                    sz=k;
                }
                else if(dungeon[k][i][j]=='E')
                {
                    ex=i;
                    ey=j;
                    ez=k;
                }
        memset(vis,0,sizeof(vis));
        BFS(sx,sy,sz);
    }
    return 0;
}
