#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=100+10;
const int inf=0x3f3f3f3f;

int head[maxn],dis[maxn],cnt,m;
bool flag[25][105]={false},broken[25]={false};

struct Edge
{
    int nex,to,w;
}edge[20*maxn];

void add(int u,int v,int w)
{
    edge[++cnt].nex=head[u];
    edge[cnt].w=w;
    edge[cnt].to=v;
    head[u]=cnt;
}

struct node
{
    int u,dis;
    node(){}
    node(int a,int b):u(a),dis(b){}
    bool operator <(const node &no) const {
        return dis>no.dis;
    }
};

int dijkstra(int l,int r)
{
    memset(dis,0x3f,sizeof dis);
    memset(broken,false,sizeof broken);
    for(int i=1;i<=m;i++)
        for(int j=l;j<=r;j++)
            if(flag[i][j]) broken[i]=true;
    dis[1]=0;
    priority_queue<node> que;
    node st(1,0);
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
            if(broken[v]) continue;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                node tmp(v,dis[v]);
                que.push(tmp);
            }
        }
    }
    return dis[m];
}

int main()
{
    int n,k,e,d,p,a,b,u,v,w;
    long long cost[105][105],dp[105];
    memset(head,0xff,sizeof head);
    cnt=0;
    scanf("%d%d%d%d",&n,&m,&k,&e);
    while(e--)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    scanf("%d",&d);
    while(d--)
    {
        scanf("%d%d%d",&p,&a,&b);
        for(int i=a;i<=b;i++)
            flag[p][i]=true;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cost[i][j]=dijkstra(i,j);
    for(int i=1;i<=n;i++)
    {
        dp[i]=cost[1][i]*i;
        for(int j=1;j<i;j++)
            dp[i]=min(dp[i],dp[j]+k+cost[j+1][i]*(i-j));
    }
    printf("%lld\n",dp[n]);
    return 0;
}
