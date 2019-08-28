#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;

const int MAX_V = 1000 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;

int head[MAX_V], dis[MAX_V], pre[MAX_V], cnt, n;

struct Edge { int nex, to, w; }edge[2*maxn];

void add(int u, int v, int w)
{
    edge[++cnt].nex = head[u];
    edge[cnt].w = w;
    edge[cnt].to = v;
    head[u] = cnt;
}

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    memset(dis, 0x3f, sizeof dis);
    que.push({0, s}); dis[s] = 0;
    while(!que.empty())
    {
        pair<int, int> f = que.top(); que.pop();
        int u = f.second, d = f.first;
        if(d != dis[u]) continue;
        for(int i = head[u]; ~i; i = edge[i].nex)
        {
            int v = edge[i].to, w = edge[i].w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                que.push({dis[v], v});
            }
        }
    }
}

struct Dinic
{
	//用于表示边的结构体（终点，流量，反向边）
	struct edge{int to, cap, rev;};

	vector<edge> G[MAX_V];	//图的邻接表表示
	int level[MAX_V];	//顶点到源点的距离标号
	int iter[MAX_V];	//当前弧

	void init(int n)
	{
		for(int i = 0; i <= n; i ++) G[i].clear();
	}

	void add(int from, int to, int cap)
	{
		G[from].push_back((edge){to, cap, G[to].size()});
		G[to].push_back((edge){from, 0, G[from].size() - 1});
	}

	//计算从源点出发的距离标号
	void bfs(int s)
	{
		memset(level, -1, sizeof(level));
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while(!que.empty())
		{
			int v = que.front(); que.pop();
			for(int i = 0; i < G[v].size(); i++)
			{
				edge &e = G[v][i];
				if(e.cap > 0 && level[e.to] < 0)
				{
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	//通过DFS寻找增广路
	int dfs(int v, int t, int f)
	{
		if(v == t) return f;
		for(int &i = iter[v]; i<G[v].size(); i++)
		{
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to])
			{
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0)
				{
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	//求解从s到t的最大流
	int max_flow(int s, int t)
	{
		int flow = 0;
		for(;;)
		{
			bfs(s);
			if(level[t] < 0) return flow;
			memset(iter, 0, sizeof(iter));
			int f;
			while((f = dfs(s,t,INF)) > 0) flow += f;
		}
	}
}dinic;

signed main()
{
    int n, m, u, v, w;
    scanf("%lld%lld", &n, &m);
    memset(head, 0xff, sizeof head);
    while(m --)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    int S = n + 1, T = n;
    for(int i = 1, x; i <= n; i ++)
    {
        scanf("%lld", &x);
        dinic.add(i, i + n, x);
    }
    dijkstra(1);
    for(int u = 1; u <= n; u ++)
    {
        for(int i = head[u]; ~i; i = edge[i].nex)
        {
            int v = edge[i].to, w = edge[i].w;
            if(dis[u] + w == dis[v]) dinic.add(u + n, v, INF);
        }
    }
    printf("%lld\n", dinic.max_flow(S, T));
    return 0;
}
