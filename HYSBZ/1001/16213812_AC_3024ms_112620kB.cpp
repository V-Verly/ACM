#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e6+10;
const int inf=0x3f3f3f3f;

int head[maxn],dis[maxn],cnt;
bool vis[maxn];

struct Edge
{
    int nex,to,w;
}edge[4*maxn];

void init()
{
    memset(head,0xff,sizeof head);
    memset(dis,inf,sizeof dis);
    memset(vis,false,sizeof vis);
    cnt=0;
}

void add_edge(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void add(int u,int v,int w)
{
    add_edge(u,v,w);
    add_edge(v,u,w);
}

void spfa(int u)
{
    queue<int> que;
    que.push(u);
    dis[u]=0;
    vis[u]=true;
    while(!que.empty())
    {
        int k=que.front();
        que.pop();
        vis[k]=false;
        for(int i=head[k];~i;i=edge[i].nex)
        {
            int v=edge[i].to;
            if(dis[k]+edge[i].w<dis[v])
            {
                dis[v]=dis[k]+edge[i].w;
                if(!vis[v]) vis[v]=true,que.push(v);
            }
        }
    }
}

int main()
{
    init();
    int n,m,val;
    scanf("%d%d",&n,&m);
    if(n==1||m==1)
    {
        if(m<n) swap(n,m);
        int ans=inf;
        for(int i=1;i<m;i++)
        {
            scanf("%d",&val);
            if(ans>val) ans=val;
        }
        printf("%d\n",ans);
        return 0;
    }
    int s=0,t=(n-1)*(m-1)*2+1,a,b;
    for(int i=1;i<m;i++) scanf("%d",&val),add(s,i,val);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            scanf("%d",&val);
            a=(i-1)*2*(m-1)+j+m-1;
            b=i*(m-1)*2+j;
            if(i==n-1) add(a,t,val);
            else add(a,b,val);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&val);
            a=(i-1)*(m-1)*2+j;
            b=(i-1)*(m-1)*2+(m-1)+j;
            if(j==1) add((i-1)*(m-1)*2+m,t,val);
            else if(j==m) add((i-1)*2*(m-1)+m-1,s,val);
            else add(a-1,b,val);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            scanf("%d",&val);
            a=(i-1)*(m-1)*2+j;
            b=(i-1)*(m-1)*2+(m-1)+j;
            add(a,b,val);
        }
    }
    spfa(s);
    printf("%d\n",dis[t]);
    return 0;
}
