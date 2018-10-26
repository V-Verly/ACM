#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e6+10;
const long long inf=0x3fffffffffffffff;

int head[maxn],cnt;
long long dis[maxn];

struct Edge
{
    int nex,to;
    long long w;
}edge[20*maxn];

void add_edge(int u,int v,long long w)
{
    edge[++cnt].nex=head[u];
    edge[cnt].w=w;
    edge[cnt].to=v;
    head[u]=cnt;
}

void add(int u,int v,long long w)
{
    add_edge(u,v,w);
    add_edge(v,u,w);
}

struct node
{
    int u;
    long long dis;
    node(){}
    node(int a,int b):u(a),dis(b){}
    bool operator <(const node &no) const
    {
        return dis>no.dis;
    }
};

void dijkstra(int s,int n)
{
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    priority_queue<node> que;
    node st(s,0);
    que.push(st);
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
                node tmp(v,dis[v]);
                que.push(tmp);
            }
        }
    }
}

long long st[maxn],en[maxn];

int main()
{
    int t,n,m,s,u;
    long long w;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        memset(head,0xff,sizeof head);
        cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%lld%d",&w,&s);
            int pt=i+n;
            while(s--)
            {
                scanf("%d",&u);
                add(pt,u,w);
            }
        }
        dijkstra(1,n+m);
        for(int i=1;i<=n;i++) st[i]=dis[i];
        dijkstra(n,n+m);
        for(int i=1;i<=n;i++) en[i]=dis[i];
        long long ans=inf;
        for(int i=1;i<=n;i++) ans=min(ans,max(st[i],en[i]));
        printf("Case #%d: ",_);
        if(ans==inf) printf("Evil John\n");
        else
        {
            printf("%lld\n",ans/2);
            bool flag=false;
            for(int i=1;i<=n;i++)
            {
                if(max(st[i],en[i])==ans)
                {
                    if(flag) printf(" ");
                    printf("%d",i);
                    flag=true;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
