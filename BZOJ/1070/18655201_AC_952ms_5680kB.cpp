#include <bits/stdc++.h>

using namespace std;

const int maxn=1e4+10;
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
    int m,n,x,t[65][10];
    scanf("%d%d",&m,&n);
    int S=0,T=n+n*m+1;
    ans.init(T);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&t[i][j]);
    for(int i=1;i<=n;i++) ans.addEdge(S,i,1,0);
    for(int i=n+1;i<=n+n*m;i++) ans.addEdge(i,T,1,0);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                ans.addEdge(k,n+(i-1)*n+j,1,t[k][i]*j);
    int cost;
    ans.mincostMaxFlow(S,T,cost);
    printf("%.2f\n",1.00*cost/n);
    return 0;
}
