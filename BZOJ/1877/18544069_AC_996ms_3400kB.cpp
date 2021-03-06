#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=400+10;
const int inf=0x3f3f3f3f;

struct Edge { int from, to, cap, flow, cost; };

struct MCMF
{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int dis[maxn], path[maxn], a[maxn];

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<=n;i++)
			G[i].clear();
		edges.clear();
	}

	void addEdge(int from, int to, int cap, int cost)
	{
		edges.push_back(Edge{from,to,cap,0,cost});
		edges.push_back(Edge{to,from,0,0,-cost});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool Bellman_Ford(int s, int t, int& flow, int& cost)
	{
		for(int i=0; i<=n; i++) dis[i]=inf;
		memset(inq, 0, sizeof inq);
		dis[s]=0, inq[s]=true, path[s]=0, a[s]=inf;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty())
		{
			int u=Q.front(); Q.pop();
			inq[u]=false;
			for(int i=0;i<G[u].size();i++)
			{
				Edge& e=edges[G[u][i]];
				if(e.cap>e.flow&&dis[e.to]>dis[u]+e.cost)
				{
					dis[e.to]=dis[u]+e.cost;
					path[e.to]=G[u][i];
					a[e.to]=min(a[u],e.cap-e.flow);
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to]=true;
					}
				}
			}
		}
		if(dis[t]==inf) return false;
		flow+=a[t];
		cost+=dis[t]*a[t];
		for(int u=t;u!=s;u=edges[path[u]].from)
		{
			edges[path[u]].flow+=a[t];
			edges[path[u]^1].flow-=a[t];
		}
		return true;
	}

	int mincostMaxFlow(int s, int t, int& cost)
	{
		int flow=0;
		cost=0;
		while(Bellman_Ford(s,t,flow,cost));
		return flow;
	}
}ans;

int main()
{
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    ans.init(2*n);
    for(int i=1;i<=n;i++)
        ans.addEdge(i,i+n,1,0);
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        ans.addEdge(u+n,v,1,w);
    }
    int res,cost;
    res=ans.mincostMaxFlow(1+n,n,cost);
    printf("%d %d\n",res,cost);
    return 0;
}
