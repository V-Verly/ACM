#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, dep[maxn], fa[maxn][20];
vector<int> G[maxn];

void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1, fa[u][0] = pre;
    for(int i = 1; (1 << i) <= n; i ++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(auto v : G[u]) if(v != pre) dfs(v, u);
}

int LCA(int u, int v)
{
    if(dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for(int i = 0; (1 << i) <= d; i ++)
        if((1 << i) & d) u = fa[u][i];
    if(u == v) return u;
    for(int i = 19; i >= 0; i --)
        if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

inline int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[LCA(u, v)]; }

int get(int a, int b, int c)
{
    return (dis(a, b) + dis(b, c) - dis(a, c)) / 2;
}

int main()
{
    int m, a, b, c;
    scanf("%d%d", &n, &m);
    for(int i = 2, x; i <= n; i ++) scanf("%d", &x), G[i].push_back(x), G[x].push_back(i);
    dfs(1, 0);
    while(m --)
    {
        scanf("%d%d%d", &a, &b, &c);
        int res = max({get(a, b, c), get(b, a, c), get(a, c, b)});
        printf("%d\n", res + 1);
    }
    return 0;
}
