#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=100+10;
const int INF=0x3f3f3f3f;

struct edge{int to,cap,rev;};

int n,f,d;
bool food[maxn][maxn],drink[maxn][maxn];
vector<edge> G[1005];
int level[1005],iter[1005];

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

void solve()
{
    int s=n*2+f+d,t=s+1;
    for(int i=0;i<f;i++)
        add(s,n*2+i,1);
    for(int i=0;i<d;i++)
        add(n*2+f+i,t,1);
    for(int i=0;i<n;i++)
    {
        add(i,n+i,1);
        for(int j=0;j<f;j++)
            if(food[i][j]) add(n*2+j,i,1);
        for(int j=0;j<d;j++)
            if(drink[i][j]) add(n+i,n*2+f+j,1);
    }
    printf("%d\n",max_flow(s,t));
}

int main()
{
    int t1,t2,u;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        memset(food,0,sizeof(food));
        memset(drink,0,sizeof(drink));
        for(int i=0;i<1005;i++) G[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            while(t1--)
            {
                scanf("%d",&u);
                food[i][u-1]=true;
            }
            while(t2--)
            {
                scanf("%d",&u);
                drink[i][u-1]=true;
            }
        }
        solve();
    }
    return 0;
}
