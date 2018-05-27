#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=3000+10;
const int inf=0x3f3f3f3f;
int m,n,ans;
char a[55][55];
int p[55][55];
int edge[maxn][maxn],mincost[maxn];
bool vis[55][55],used[maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct node
{
    int x,y,step;
    node(){}
    node(int xx,int yy,int s):x(xx),y(yy),step(s){}
};

void bfs(int sx,int sy)
{
    node st(sx,sy,0);
    queue <node> que;
    que.push(st);
    memset(vis,false,sizeof(vis));
    vis[sx][sy]=true;
    while(!que.empty())
    {
        node k=que.front();
        que.pop();
        if(p[k.x][k.y])
            edge[p[st.x][st.y]][p[k.x][k.y]]=edge[p[k.x][k.y]][p[st.x][st.y]]=k.step;
        for(int i=0;i<4;i++)
        {
            int fx=k.x+dx[i],fy=k.y+dy[i];
            if(fx>=0&&fx<m&&fy>=0&&fy<n&&!vis[fx][fy]&&a[fx][fy]!='#')
            {
                node r(fx,fy,k.step+1);
                vis[fx][fy]=true;
                que.push(r);
            }
        }
    }
}

void prim()
{
    for(int i=1;i<=ans;i++)
        mincost[i]=edge[i][1],used[i]=false;
    used[1]=true;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=ans;u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        used[v]=true;
        for(int u=1;u<=ans;u++)
            if(!used[u]) mincost[u]=min(edge[u][v],mincost[u]);
    }
    printf("%d\n",res);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d\n",&n,&m);
        getchar();
        for(int i=0;i<m;i++)
        {
            gets(a[i]);
        }
        ans=0;
        memset(p,0,sizeof(p));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='A'||a[i][j]=='S') p[i][j]=++ans;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(p[i][j])
                {
                    bfs(i,j);
                    edge[p[i][j]][p[i][j]]=inf;
                }
            }
        }
        prim();
    }
    return 0;
}
