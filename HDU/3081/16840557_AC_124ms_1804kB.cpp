#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=200+10;
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

int pre[105];

int Find(int x) { return x==pre[x]?x:pre[x]=Find(pre[x]); }

void join(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b) pre[b]=a;
}

int main()
{
    int T,n,m,f,u,v;
    int match[105][105],cnt[105];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&f);
        int s=0,t=2*n+1;
        for(int i=1;i<=n;i++) pre[i]=i;
        memset(match,0,sizeof match);
        memset(cnt,0,sizeof cnt);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            match[u][v]=1;
        }
        while(f--)
        {
            scanf("%d%d",&u,&v);
            join(u,v);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(match[i][j]) match[Find(i)][j]=1;
        int l=0,r=INF,limit,res=-1;
        while(r>l)
        {
            limit=(l+r)>>1;
            for(int i=0;i<=t;i++) G[i].clear();
            for(int i=1;i<=n;i++) add(i+n,t,limit);
            for(int i=1;i<=n;i++) add(s,i,limit);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(match[Find(i)][j]) add(i,j+n,1);
            int ans=max_flow(s,t);
            if(n*limit==ans) l=limit+1,res=limit;
            else r=limit;
        }
        printf("%d\n",res==-1?0:res);
    }
    return 0;
}
