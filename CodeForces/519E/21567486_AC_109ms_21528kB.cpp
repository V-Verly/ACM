#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, dep[maxn], fa[maxn][30], sz[maxn];
vector<int> G[maxn];

void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1, fa[u][0] = pre, sz[u] = 1;
    for(int i = 1; (1 << i) <= n; i ++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(auto v : G[u]) if(v != pre) dfs(v, u), sz[u] += sz[v];
}

int LCA(int u, int v)
{
    if(dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for(int i = 0; (1 << i) <= d; i ++)
        if((1 << i) & d) u = fa[u][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i --)
        if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int get(int d, int u)
{
    for(int i = 20; i >= 0; i --)
        if(d >= (1 << i)) u = fa[u][i], d -= (1 << i);
    return u;
}

int main()
{
    int m, u, v;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    scanf("%d", &m);
    while(m --)
    {
        scanf("%d%d", &u, &v);
        if(u == v) { printf("%d\n", n); continue; }
        int root = LCA(u, v), len = dep[u] + dep[v] - 2 * dep[root];
        if((dep[u] + dep[v] - 2 * dep[root]) % 2) puts("0");
        else if(dep[u] - dep[root] == dep[v] - dep[root])
        {
            int x = get(dep[u] - dep[root] - 1, u), y = get(dep[v] - dep[root] - 1, v);
            printf("%d\n", n - sz[x] - sz[y]);
        }
        else
        {
            len = len / 2;
            if(dep[u] < dep[v]) swap(u, v);
            int x = get(len, u), y = get(len - 1, u);
            printf("%d\n", sz[x] - sz[y]);
        }
    }
    return 0;
}
