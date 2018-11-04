#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

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
    int n,m,h[105][2];
    char mp[105][105];
    while(scanf("%d%d",&n,&m)!=EOF&&(n&&m))
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='H')
                {
                    h[cnt][0]=i;
                    h[cnt++][1]=j;
                }
            }
        }
        int s=2*cnt+1,t=s+1,tmp=0;
        ans.init(t);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='m')
                {
                    for(int k=0;k<cnt;k++)
                    {
                        int l=abs(i-h[k][0])+abs(j-h[k][1]);
                        ans.addEdge(tmp,k+cnt,1,l);
                    }
                    tmp++;
                }
            }
        }
        for(int i=0;i<cnt;i++)
        {
            ans.addEdge(s,i,1,0);
            ans.addEdge(i+cnt,t,1,0);
        }
        int cost;
        ans.mincostMaxFlow(s,t,cost);
        printf("%d\n",cost);
    }
    return 0;
}
