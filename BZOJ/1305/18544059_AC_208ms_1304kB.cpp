#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V=500+10;
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

char a[55][55];
int S,T,n,k;

bool check(int x)
{
    for(int i=0;i<=T;i++) G[i].clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) if(a[i][j]=='Y') add(i,j+n,1);
        add(S,i,x);add(i+n,i+4*n,INF);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) if(a[i][j]!='Y') add(2*n+i,j+3*n,1);
        add(i,2*n+i,k);add(i+3*n,i+4*n,k);
    }
    for(int i=1;i<=n;i++) add(i+4*n,T,x);
    return max_flow(S,T)==x*n;
}

int main()
{

    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    S=0,T=5*n+1;
    int l=0,r=INF,mid,ans;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
