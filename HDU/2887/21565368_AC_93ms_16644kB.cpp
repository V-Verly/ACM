#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;

int pre[maxn], n, m, p;

struct edge{
    int u, v, w;
    bool operator < (const edge &e) const { return w < e.w; }
 }es[maxm];

int Find(int x) { return x == pre[x] ? x : pre[x] = Find(pre[x]); }

bool Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if(fx == fy) return false;
    pre[fx] = fy;
    return true;
}

vector<pair<int, int> > G[maxn];
int dep[maxn], fa[maxn][30], val[maxn][30];

void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1, fa[u][0] = pre;
    for(int i = 1; (1 << i) <= n; i ++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1], val[u][i] = max(val[u][i - 1], val[fa[u][i - 1]][i - 1]);
    for(auto v : G[u]) if(v.first != pre) val[v.first][0] = v.second, dfs(v.first, u);

}

int LCA(int u, int v)
{
    int res = 0;
    if(dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for(int i = 0; (1 << i) <= d; i ++)
        if((1 << i) & d) res = max(res, val[u][i]), u = fa[u][i];
    if(u == v) return res;
    for(int i = 19; i >= 0; i --)
        if(fa[u][i] != fa[v][i]) res = max(res, val[u][i]), res = max(res, val[v][i]), u = fa[u][i], v = fa[v][i];
    return max({res, val[u][0], val[v][0]});
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &p) != EOF)
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &es[i].w);
            es[i].u = 0, es[i].v = i;
        }
        for(int i = n + 1; i <= n + m; i ++)
            scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
        m += n;
        for(int i = 0; i <= n; i ++) pre[i] = i, G[i].clear();
        memset(val, 0, sizeof val);
        sort(es + 1, es + m + 1);
        int tot = 0;
        for(int i = 1; i <= m; i ++) if(Union(es[i].u, es[i].v))
        {
            tot += es[i].w;
            G[es[i].u].push_back({es[i].v, es[i].w});
            G[es[i].v].push_back({es[i].u, es[i].w});
        }
        dfs(0, -1);
        while(p --)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", tot - LCA(u, v));
        }
    }
    return 0;
}
