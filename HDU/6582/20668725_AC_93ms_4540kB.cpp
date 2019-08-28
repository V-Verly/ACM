#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 10000 + 10;
const int INF = 0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edges{int to, cap, rev; };

struct Dinic
{
	vector<edges> G[maxn];	//图的邻接表表示
	int level[maxn];	//顶点到源点的距离标号
	int iter[maxn];	//当前弧

	void init()
	{
	    for(int i = 1; i < maxn; i ++) G[i].clear();
	}
	
	void add(int from, int to, int cap)
	{
		G[from].push_back((edges){to, cap, G[to].size()});
		G[to].push_back((edges){from, 0, G[from].size() - 1});
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
				edges &e = G[v][i];
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
			edges &e = G[v][i];
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

struct Edge { int nex, to, tot, w; }edge[maxn];

struct Dijkstra
{
    int head[maxn], dis[maxn], cnt;

    void init()
    {
        memset(head, 0xff, sizeof head);
        cnt = 0;
    }

    void add(int u, int v, int w)
    {
        if(u == v) return;
        int p = -1;
        for(int i = head[u]; ~i; i = edge[i].nex) if(edge[i].to == v) { p = i; break; }
        if(~p)
        {
            if(w < edge[p].w) edge[p].w = w, edge[p].tot = 1;
            else if(w == edge[p].w) edge[p].tot ++;
            return;
        }
        edge[++cnt].nex = head[u];
        edge[cnt].w = w;
        edge[cnt].to = v;
        edge[cnt].tot = 1;
        head[u] = cnt;
    }

    void dijkstra(int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
        memset(dis, 0x3f, sizeof dis);
        que.push({0, s}); dis[s] = 0;
        while(!que.empty())
        {
            auto f = que.top(); que.pop();
            int u = f.second, d = f.first;
            if(d != dis[u]) continue;
            for(int i = head[u]; ~i; i = edge[i].nex)
            {
                int v = edge[i].to, w = edge[i].w;
                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    que.push({dis[v], v});
                    dinic.add(u, v, w * edge[i].tot);
                }
                else if(dis[u] + w == dis[v]) dinic.add(u, v, w * edge[i].tot);
            }
        }
    }
}G;

signed main()
{
    int t, n, m, u, v, w;
    scanf("%lld", &t);
    while(t --)
    {
        scanf("%lld%lld", &n, &m);
        G.init();
        dinic.init();
        while(m --)
        {
            scanf("%lld%lld%lld", &u, &v, &w);
            G.add(u, v, w);
        }
        G.dijkstra(1);
        printf("%lld\n", dinic.max_flow(1, n));
    }
    return 0;
}
