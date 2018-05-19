#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char a[2][12][12];
int m,n,t,x,y,z;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int vis[2][12][12];

struct point{
int z,x,y;
int time;
};

void BFS()
{
    point st;
    st.x=st.y=st.z=st.time=0;
    queue <point> que;
    bool flag=false;
    vis[0][0][0]=1;
    que.push(st);
    while(!que.empty())
    {
        point k=que.front();
        que.pop();
        if(k.x==x&&k.y==y&&k.z==z)
        {
            if(k.time<=t) flag=true;
            break;
        }
        if(a[k.z][k.x][k.y]=='#')
        {
            int fz=!k.z;
            if(a[fz][k.x][k.y]!='*'&&a[fz][k.x][k.y]!='#'&&!vis[fz][k.x][k.y])
            {
                vis[fz][k.x][k.y]=1;
                point r;
                r.x=k.x;
                r.y=k.y;
                r.z=fz;
                r.time=k.time;
                que.push(r);
            }
        }
        else{
            for(int i=0;i<4;i++)
            {
                int fx=k.x+dx[i];
                int fy=k.y+dy[i];
                int fz=k.z;
                if(fx>=0&&fx<n&&fy>=0&&fy<m)
                {
                    if(!vis[fz][fx][fy]&&a[fz][fx][fy]!='*')
                       {
                           vis[fz][fx][fy]=1;
                           point r;
                           r.x=fx;
                           r.y=fy;
                           r.z=fz;
                           r.time=k.time+1;
                           que.push(r);
                       }
                }
            }
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int c,i,j;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for(i=0;i<n;i++)
            scanf("%s",a[0][i]);
        for(i=0;i<n;i++)
            scanf("%s",a[1][i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(a[0][i][j]=='P') {
                    x=i;
                    y=j;
                    z=0;
                    break;
                }
                else if(a[1][i][j]=='P') {
                    x=i;
                    y=j;
                    z=1;
                    break;
                }
            }
        memset(vis,0,sizeof(vis));
        BFS();
    }
    return 0;
}
