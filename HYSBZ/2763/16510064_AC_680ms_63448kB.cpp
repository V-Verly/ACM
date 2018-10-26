#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e6+10;
const int inf=0x3f3f3f3f;

int cnt,head[maxn],dis[maxn];

struct Edge
{
    int nex,to,w;
}edge[2*maxn];

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

struct node
{
    int u,dis;
    bool operator<(const node &no) const {
        return dis>no.dis;
    }
};

void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    priority_queue<node> que;
    node st{s,0};
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
                node tmp{v,dis[v]};
                que.push(tmp);
            }
        }
    }
}

int main()
{
    int n,m,k,s,t,u,v,w;
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    memset(head,0xff,sizeof head);
    cnt=0;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;j<=k;j++)
        {
            add(j*n+u,j*n+v,w);
            if(j<k)
            {
                add_edge(j*n+u,(j+1)*n+v,0);
                add_edge(j*n+v,(j+1)*n+u,0);
            }
        }
    }
    dijkstra(s);
    int ans=inf;
    for(int i=0;i<=k;i++)
        ans=min(ans,dis[i*n+t]);
    printf("%d\n",ans);
    return 0;
}
