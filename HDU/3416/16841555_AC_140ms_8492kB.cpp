#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=1000+10;
const int INF=0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edge{int to,cap,rev;};

vector<edge> G[MAX_V];	//图的邻接表表示
int level[MAX_V];	//顶点到源点的距离标号
int iter[MAX_V];	//当前弧

void add(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

//计算从源点出发的距离标号
void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>0&&level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

//通过DFS寻找增广路
int dfs(int v,int t,int f)
{
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

//求解从s到t的最大流
int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0) flow+=f;
	}
}

int head[MAX_V],dis[MAX_V],rehead[MAX_V],redis[MAX_V],cnt,n;

struct Edge
{
    int nex,to,w;
}edge1[100*MAX_V],edge2[100*MAX_V];

void add_edge(int u,int v,int w)
{
    edge1[cnt].nex=head[u];
    edge1[cnt].w=w;
    edge1[cnt].to=v;
    head[u]=cnt;
    edge2[cnt].nex=rehead[v];
    edge2[cnt].w=w;
    edge2[cnt].to=u;
    rehead[v]=cnt++;
}

struct node
{
    int u,dis;
    node(){}
    node(int a,int b):u(a),dis(b){}
    bool operator <(const node &no) const
    {
        return dis>no.dis;
    }
};

void dijkstra(int s)
{
    for(int i=1;i<=n;i++) dis[i]=INF;
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
        for(int i=head[u];~i;i=edge1[i].nex)
        {
            int v=edge1[i].to,w=edge1[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                node tmp(v,dis[v]);
                que.push(tmp);
            }
        }
    }
}

void dijkstra1(int s)
{
    for(int i=1;i<=n;i++) redis[i]=INF;
    redis[s]=0;
    priority_queue<node> que;
    node st(s,0);
    que.push(st);
    while(!que.empty())
    {
        node f=que.top();
        que.pop();
        int u=f.u,d=f.dis;
        if(d!=redis[u]) continue;
        for(int i=rehead[u];~i;i=edge2[i].nex)
        {
            int v=edge2[i].to,w=edge2[i].w;
            if(redis[u]+w<redis[v])
            {
                redis[v]=redis[u]+w;
                node tmp(v,redis[v]);
                que.push(tmp);
            }
        }
    }
}

int a[100*MAX_V],b[100*MAX_V],c[100*MAX_V];

int main()
{
    int T,m,u,v,w,s,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(head,0xff,sizeof head);
        memset(rehead,0xff,sizeof rehead);
        cnt=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            a[i]=u,b[i]=v,c[i]=w;
        }
        scanf("%d%d",&s,&t);
        dijkstra(s);
        dijkstra1(t);
        int len=dis[t];
        for(int i=0;i<m;i++)
            if(dis[a[i]]+redis[b[i]]+c[i]==len) add(a[i],b[i],1);
        printf("%d\n",max_flow(s,t));
    }
    return 0;
}
