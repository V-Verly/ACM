#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17;
const int maxn = 1000 + 10;

struct Edge { int u, v; long long cost; } edge[maxn * maxn];

int pre[maxn], vis[maxn], id[maxn], pos;
long long in[maxn];

long long zhuliu(int root, int n, int m)
{
    long long res = 0;
    int u, v;
    for (;;)
    {
        for (int i = 0; i < n; i++) in[i] = INF;
        for (int i = 0; i < m; i++)
            if (edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v])
            {
                pre[edge[i].v] = edge[i].u;
                in[edge[i].v] = edge[i].cost;
                if (edge[i].u == root) pos = i;
            }
        for (int i = 0; i < n; i++) if (i != root && in[i] == INF) return -1;
        int tn = 0;
        memset(id, 0xff, sizeof id);
        memset(vis, 0xff, sizeof vis);
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            res += in[i];
            v = i;
            while (vis[v] != i && id[v] == -1 && v != root) vis[v] = i, v = pre[v];
            if (v != root && id[v] == -1)
            {
                for (int u = pre[v]; u != v; u = pre[u]) id[u] = tn;
                id[v] = tn++;
            }
        }
        if (tn == 0) break;
        for (int i = 0; i < n; i++) if (id[i] == -1) id[i] = tn++;
        for (int i = 0; i < m; i++)
        {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            edge[i].cost -= in[v];
        }
        n = tn;
        root = id[root];
    }
    return res;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%lld", &edge[i].u, &edge[i].v, &edge[i].cost);
            edge[i].u++;
            edge[i].v++;
            sum += edge[i].cost;
        }
        sum++;
        int root = 0;
        for (int i = m; i < m + n; i++)
            edge[i].u = root, edge[i].v = i - m + 1, edge[i].cost = sum;
        long long res = zhuliu(root, n + 1, m + n);
        if (res == -1 || res - sum >= sum) printf("impossible\n\n");
        else printf("%lld %d\n\n", res - sum, pos - m);
    }
    return 0;
}
