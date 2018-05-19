#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int m,vis[10005];
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
struct num{
int t;
int step;
};
void BFS(int x)
{
    queue <num> que;
    num a;
    a.t=x;
    a.step=0;
    que.push(a);
    while(!que.empty())
    {
        num k;
        k=que.front();
        que.pop();
        if(k.t==m) {
            printf("%d\n",k.step);
            return;
        }
        for(int i=1;i<=9;i+=2)
        {
            int s=k.t/10*10+i;
            int r=k.step+1;
            num tmp;
            if(isprime(s)&&!vis[s])
            {
                tmp.t=s;
                tmp.step=r;
                que.push(tmp);
                vis[s]=1;
            }
        }
        for(int i=0;i<=9;i++)
        {
            int s=k.t/100*100+k.t%10+i*10;
            int r=k.step+1;
            num tmp;
            if(isprime(s)&&!vis[s])
            {
                tmp.t=s;
                tmp.step=r;
                que.push(tmp);
                vis[s]=1;
            }
        }
        for(int i=0;i<=9;i++)
        {
            int s=k.t/1000*1000+k.t%100+i*100;
            int r=k.step+1;
            num tmp;
            if(isprime(s)&&!vis[s])
            {
                tmp.t=s;
                tmp.step=r;
                que.push(tmp);
                vis[s]=1;
            }
        }
        for(int i=1;i<=9;i++)
        {
            int s=k.t%1000+i*1000;
            int r=k.step+1;
            num tmp;
            if(isprime(s)&&!vis[s])
            {
                tmp.t=s;
                tmp.step=r;
                que.push(tmp);
                vis[s]=1;
            }
        }
    }
    printf("Impossible\n");
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        BFS(n);
    }
    return 0;
}
