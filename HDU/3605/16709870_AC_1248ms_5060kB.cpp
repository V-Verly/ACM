#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=1e5+10;
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

int main()
{
    int n,m,f,w,p[1210];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int s=0,t=(1<<m)+m+1;
        for(int i=0;i<=t;i++)
            G[i].clear();
        memset(p,0,sizeof p);
        for(int i=0;i<n;i++)
        {
            int a=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&f);
                a<<=1;
                if(f) a|=1;
            }
            p[a]++;
        }
        for(int i=0;i<(1<<m);i++)
        {
            add(s,i+1,p[i]);
            for(int j=m-1;j>=0;j--)
            {
                if((i>>j)&1) add(i+1,m-j+(1<<m),p[i]);
            }
        }
        for(int i=(1<<m)+1;i<=(1<<m)+m;i++)
        {
            scanf("%d",&w);
            add(i,t,w);
        }
        printf("%s\n",max_flow(s,t)==n?"YES":"NO");
    }
    return 0;
}
