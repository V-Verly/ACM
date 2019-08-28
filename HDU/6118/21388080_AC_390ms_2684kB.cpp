#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;

struct Edge { int from, to, cap, flow, cost; };

struct MCMF
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int dis[maxn], path[maxn], a[maxn];

	void init(int n)
	{
		this->n = n;
		for(int i = 0;i <= n;i ++)
			G[i].clear();
		edges.clear();
	}

	void addEdge(int from, int to, int cap, int cost)
	{
		edges.push_back(Edge{from, to, cap, 0, cost});
		edges.push_back(Edge{to, from, 0, 0, -cost});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool Bellman_Ford(int s, int t, int& flow, int& cost)
	{
		for(int i = 0; i<= n; i++) dis[i] = inf;
		memset(inq, 0, sizeof inq);
		dis[s]=0, inq[s]=true, path[s]=0, a[s]=inf;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front(); Q.pop();
			inq[u] = false;
			for(int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if(e.cap > e.flow && dis[e.to] > dis[u] + e.cost)
				{
					dis[e.to] = dis[u] + e.cost;
					path[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = true;
					}
				}
			}
		}
		if(dis[t] * a[t] > 0) return false;
		flow += a[t];
		cost += dis[t] * a[t];
		for(int u = t; u != s; u = edges[path[u]].from)
		{
			edges[path[u]].flow += a[t];
			edges[path[u] ^ 1].flow -= a[t];
		}
		return true;
	}

	int mincostMaxFlow(int s, int t)
	{
		int flow = 0, cost = 0;
		while(Bellman_Ford(s, t, flow, cost));
		return cost;
	}
}ans;

int mp[maxn][maxn];

int main()
{
    int n, m, a, b, c, d, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int S = 0, T = n + 1;
        ans.init(T);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            ans.addEdge(S, i, b, a);
            ans.addEdge(i, T, d, -c);
        }
        memset(mp, 0x3f, sizeof mp);
        while(m --)
        {
            scanf("%d%d%d", &u, &v, &w);
            mp[u][v] = mp[v][u] = min(w, mp[u][v]);
        }
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                if(i != j && mp[i][j] != inf) ans.addEdge(i, j, inf, mp[i][j]);
        cout << -ans.mincostMaxFlow(S, T) << endl;
    }
    return 0;
}
