#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e5+10;;
const int inf=0x3f3f3f3f;

int n,head[maxn],cnt;
int layer[maxn],mark[maxn],dis[maxn];

struct Edge
{
    int nex,to,w;
}edge[10*maxn];

struct node
{
    int u,dis;
    bool operator <(const node &no) const
    {
        return dis>no.dis;
    }
};

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void dijkstra(int s)
{
    dis[s]=0;
    priority_queue<node> que;
    que.push({s,0});
    while(!que.empty())
    {
        node f=que.top();
        que.pop();
        int u=f.u,d=f.dis;
        if(d!=dis[u]) continue;
        for(int i=head[u];~i;i=edge[i].nex)
        {
            int v=edge[i].to,w=edge[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                que.push({v,dis[v]});
            }
        }
    }
}

int main()
{
    int t,m,c,u,v,w;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        cnt=0;
        scanf("%d%d%d",&n,&m,&c);
        memset(head,0xff,sizeof(head));
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&layer[i]);
            mark[layer[i]]++;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        for(int i=2;i<=n;i++)
        {
            if(mark[i]&&mark[i-1])
            {
                add(i+n,i+n-1,c);
                add(i+n-1,i+n,c);
            }
        }
        for(int i=1;i<=n;i++)
        {
            dis[i]=dis[i+n]=inf;
            add(layer[i]+n,i,0);
            if(layer[i]>1) add(i,layer[i]+n-1,c);
            if(layer[i]<n) add(i,layer[i]+n+1,c);
        }
        dijkstra(1);
        printf("Case #%d: %d\n",_,(dis[n]==inf||!n)?-1:dis[n]);
    }
    return 0;
}
