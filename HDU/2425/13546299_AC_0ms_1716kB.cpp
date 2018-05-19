#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int r,c,p,s,t,sx,sy,ex,ey;
char a[105][105];
bool vis[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct point
{
    int x,y,step;
    bool operator <(const point &t)const
    {
        return step>t.step;
    }
};

void BFS()
{
    point st;
    st.x=sx;
    st.y=sy;
    st.step=0;
    vis[sx][sy]=true;
    priority_queue <point> que;
    que.push(st);
    while(!que.empty())
    {
        point k=que.top();
        que.pop();
        //printf("%d\n",k.step);
        if(k.x==ex&&k.y==ey)
        {
            printf("%d\n",k.step);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i];
            int fy=k.y+dy[i];
            if(fx>=0&&fx<r&&fy>=0&&fy<c&&!vis[fx][fy])
            {
                vis[fx][fy]=true;
                if(a[fx][fy]=='@') continue;
                point tmp;
                tmp.x=fx;
                tmp.y=fy;
                if(a[fx][fy]=='T') tmp.step=k.step+t;
                else if(a[fx][fy]=='.') tmp.step=k.step+s;
                else if(a[fx][fy]=='#') tmp.step=k.step+p;
                que.push(tmp);
            }
        }
    }
    printf("%d\n",-1);
}

int main()
{
    int count=0;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        scanf("%d%d%d",&p,&s,&t);
        for(int i=0;i<r;i++)
            scanf("%s",a[i]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        memset(vis,false,sizeof(vis));
        printf("Case %d: ",++count);
        BFS();
        
    }
    return 0;
}