#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e5+10;
int n,k;
int vis[maxn];
struct po{
int x,step;
};
void BFS(int x)
{
    po a;
    a.x=x;
    a.step=0;
    queue <po> que;
    que.push(a);
    while(!que.empty())
    {
        po r=que.front();
        que.pop();
        if(r.x==k) {printf("%d\n",r.step);break;}
        if(r.x+1<maxn&&!vis[r.x+1])
        {
            vis[r.x+1]=1;
            po s;
            s.x=r.x+1;
            s.step=r.step+1;
            que.push(s);
        }
        if(r.x-1>=0&&!vis[r.x-1])
        {
            vis[r.x-1]=1;
            po s;
            s.x=r.x-1;
            s.step=r.step+1;
            que.push(s);
        }
        if(r.x*2<maxn&&!vis[r.x*2])
        {
            vis[r.x*2]=1;
            po s;
            s.x=r.x*2;
            s.step=r.step+1;
            que.push(s);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        BFS(n);
    }
    return 0;
}
