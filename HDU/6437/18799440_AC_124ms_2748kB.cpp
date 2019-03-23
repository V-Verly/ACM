#include <bits/stdc++.h>

using namespace std;

using namespace std;

const int maxn=10000+10;
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
    int _,s[205],t[205],op[205],w[205];
    scanf("%d",&_);
    while(_--)
    {
        int n,m,k,W;
        scanf("%d%d%d%d",&n,&m,&k,&W);
        int S=0,T=2*m+k+1;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d%d",&s[i],&t[i],&w[i],&op[i]);
        ans.init(T);
        for(int i=1;i<=k;i++)
        {
            ans.addEdge(S,2*m+i,1,0);
            for(int j=1;j<=m;j++) ans.addEdge(2*m+i,j,1,0);
        }
        for(int i=1;i<=m;i++)
        {
            ans.addEdge(i,i+m,1,-w[i]);
            ans.addEdge(i+m,T,1,0);
            for(int j=1;j<=m;j++)
            {
                if(t[i]<=s[j])
                {
                    if(op[i]==op[j]) ans.addEdge(i+m,j,1,W);
                    else ans.addEdge(i+m,j,1,0);
                }
            }
        }
        int res;
        ans.mincostMaxFlow(S,T,res);
        printf("%d\n",-res);
    }

    return 0;
}
