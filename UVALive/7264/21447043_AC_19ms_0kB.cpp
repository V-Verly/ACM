#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1000 + 10;
const int INF = 0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];	//图的邻接表表示
int level[MAX_V];	//顶点到源点的距离标号
int iter[MAX_V];	//当前弧

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

int main()
{
    int _, n, m, p, a, b, c;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d%d%d", &n, &m, &p);
        int S = 0, T = 2 * n + 1;
        for(int i = 0; i <= T; i ++) G[i].clear();
        while(m --)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a + n, b, c);
        }
        for(int i = 1; i <= n; i ++) scanf("%d", &c), add(S, i, c);
        for(int i = 1; i <= n; i ++) scanf("%d", &c), add(i, i + n, c);
        add(p + n, T, INF);
        printf("%d\n", max_flow(S, T));
    }
    return 0;
}
