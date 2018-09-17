#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=1e5+10;
bool vis[maxn];

struct Node
{
    int x, step;
};

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        vis[n]=true;
        queue<Node> que;
        que.push({n,0});
        bool flag=true;
        while(!que.empty())
        {
            Node k=que.front();
            que.pop();
            if(m==k.x)
            {
                printf("%d\n",k.step);
                break;
            }
            if(k.x*2<=100000&&!vis[k.x*2])
            {
                que.push({k.x*2,k.step+1});
                vis[k.x*2]=true;
            }
            if(k.x+1<=100000&&!vis[k.x+1])
            {
                que.push({k.x+1,k.step+1});
                vis[k.x+1]=true;
            }
            if(k.x-1>=0&&!vis[k.x-1])
            {
                que.push({k.x-1,k.step+1});
                vis[k.x-1]=true;
            }
        }
    }
    return 0;
}
