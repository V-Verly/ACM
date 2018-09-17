#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,st,en,a[205];
bool vis[205];

struct Node{int x,step;};

void BFS()
{
    Node s{st,0};
    queue<Node> que;
    que.push(s);
    vis[st]=true;
    while(!que.empty())
    {
        Node tmp=que.front();
        que.pop();
        if(tmp.x==en)
        {
            printf("%d\n",tmp.step);
            return;
        }
        if(tmp.x+a[tmp.x]<=n&&!vis[tmp.x+a[tmp.x]])
        {
            que.push({tmp.x+a[tmp.x],tmp.step+1});
            vis[tmp.x+a[tmp.x]]=true;
        }
        if(tmp.x-a[tmp.x]>0&&!vis[tmp.x-a[tmp.x]])
        {
            que.push({tmp.x-a[tmp.x],tmp.step+1});
            vis[tmp.x-a[tmp.x]]=true;
        }
    }
    printf("-1\n");
}

int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d%d",&st,&en);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        BFS();
    }
    return 0;
}
