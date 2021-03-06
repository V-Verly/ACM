#include <bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=1000;
const int maxm=10000;

struct Edge{int u,v,cost; } edge[maxm];

int pre[maxn], id[maxn], vis[maxn], in[maxn];

int zhuliu(int root, int n, int m)
{
	int res=0, u, v;
	for(;;)
	{
		for(int i=0; i<n; i++) in[i] = INF;
		for(int i=0; i<m; i++) if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v])
		{
			pre[edge[i].v] = edge[i].u;
			in[edge[i].v] = edge[i].cost;
		}
		for(int i=0; i<n; i++) if(i != root && in[i] ==INF) return -1;
		int tn=0;
		memset(id, 0xff, sizeof id);
		memset(vis, 0xff, sizeof vis);
		in[root] = 0;
		for(int i=0; i<n;i++)
		{
			res += in[i];
			v = i;
			while( vis[v] != i && id[v] == -1 && v!= root) vis[v] = i, v = pre[v];
			if(v != root && id[v] == -1)
			{
				for(int u = pre[v]; u != v; u = pre[u]) id[u] = tn;
				id[v] = tn++;
			}
		}
		if(tn == 0) break;
		for(int i=0; i<n; i++) if(id[i] == -1) id[i] = tn++;
		for(int i=0; i<m;)
		{
			v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if(edge[i].u != edge[i].v) edge[i++].cost -= in[v];
			else swap(edge[i], edge[--m]);
		}
		n = tn;
		root = id[root];
	}
	return res;
}

int main()
{
    int t, n, m, u, v, w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d",&n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&edge[i].u, &edge[i].v, &edge[i].cost);
            edge[i].u--;
            edge[i].v--;
            edge[i].cost = -edge[i].cost * 1000;
            if(edge[i].v == n - 1) edge[i].cost += edge[i].u;
        }
        int res = -zhuliu(0, n, m);
        int ans = (res + 999) / 1000, pos = ans * 1000 - res;
        printf("%d %d\n", ans, pos + 1);
    }
    return 0;
}
