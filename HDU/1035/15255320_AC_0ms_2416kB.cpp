#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
char mp[1005][1005];
bool vis[1005][1005];
int step[1005][1005];

struct Node
{
    int x,y,step;
};

bool check(int x,int y)
{
    return x<0||x>=n||y<0||y>=m;
}

void BFS(int x,int y)
{
    Node st{x,y,0};
    vis[x][y]=true;
    queue <Node> que;
    que.push(st);
    while(!que.empty())
    {
        Node k=que.front();
        que.pop();
        int fx=k.x,fy=k.y;

        if(mp[k.x][k.y]=='N') fx--;
        else if(mp[k.x][k.y]=='S') fx++;
        else if(mp[k.x][k.y]=='E') fy++;
        else if(mp[k.x][k.y]=='W') fy--;
        if(check(fx,fy))
        {
            printf("%d step(s) to exit\n",k.step+1);
            return;
        }
        else if(vis[fx][fy])
        {
            printf("%d step(s) before a loop of %d step(s)\n",step[fx][fy],k.step+1-step[fx][fy]);
            return;
        }
        step[fx][fy]=k.step+1;
        k.x=fx,k.y=fy,k.step++;
        que.push(k);
        vis[fx][fy]=true;
    }
}

int main()
{
    int st;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        scanf("%d",&st);
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        memset(vis,0,sizeof(vis));
        BFS(0,st-1);
    }
    return 0;
}
