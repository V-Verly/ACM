/*************************************************************************
	> File Name: A.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月02日 星期五 20时54分32秒
 ************************************************************************/

#include <cstdio>
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

int p,st[15],en[15];
int S[55][15],D[55][15];

bool check(int *s,int *e)
{
	for(int i=0;i<p;i++)
	{
		if(s[i]==2) continue;
		if(s[i]!=e[i]) return false;
	}
	return true;
}

int main()
{
	int n,w[15],mp[55][55];
	for(int i=0;i<15;i++)
		st[i]=0,en[i]=1;
	while(scanf("%d%d",&p,&n)!=EOF)
	{
		int s=0,t=2*n+1;
		for(int i=0;i<=t;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			for(int j=0;j<p;j++)
				scanf("%d",&S[i][j]);
			for(int j=0;j<p;j++)
				scanf("%d",&D[i][j]);
		}
		memset(mp,0xff,sizeof mp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				if(check(S[i],D[j])) add(j+n,i,INF),mp[j][i]=G[j+n].size()-1;
			add(i,i+n,w[i]);
			if(check(S[i],st)) add(s,i,INF);
			if(check(en,D[i])) add(i+n,t,INF);
		}
		int ans=max_flow(s,t),cnt=0;
		int res[105][105];
		memset(res,0,sizeof res);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(~mp[i][j])
				{
					if(G[i+n][mp[i][j]].cap<INF)
					{
						res[i][j]=INF-G[i+n][mp[i][j]].cap;
						cnt++;
					}
				}
			}
		}
		printf("%d %d\n",ans,cnt);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(res[i][j]) printf("%d %d %d\n",i,j,res[i][j]);
	}
	return 0;
}