#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 10;

vector <int> edge[maxn];

int n;
int dep[maxn], fa[maxn][30];

void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    for(int i = 1; (1 << i) <= n; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(v != pre) dfs(v, u);
    }
}

int LCA(int u, int v)
{
    if(dep[u] < dep[v]) swap(u, v);

    int d = dep[u] - dep[v];
    for(int i = 0; (1 << i) <= d; i ++)
        if((1 << i) & d) u = fa[u][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; i--)
    {
        if(fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int pre[maxn], sz[maxn], ans;

int find(int x) {return x == pre[x] ? x : pre[x] = find(pre[x]); }

void Union(int x, int y)
{
    x = find(x);
    if(dep[fa[x][0]] <= dep[y] || fa[x][0] == 0) return;
    ans = ans ^ sz[fa[x][0]] ^ (sz[fa[x][0]] - 1);
    sz[fa[x][0]] --;
    pre[x] = fa[x][0];
    Union(fa[x][0], y);
}

int main()
{
    int m, a, b, x, y, u, v;
    while(scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y) != EOF)
    {
        for(int i = 1; i <= n; i++) edge[i].clear(), pre[i] = i;
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            u++; v++;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            sz[i] = edge[i].size();
            ans ^= sz[i];
        }
        dfs(1, 0);
        for(int i = 0; i < m; i++)
        {
            int tx = (a * x + b * y + ans) % n;
            int ty = (b * x + a * y + ans) % n;
            x = tx, y = ty;
            Union(x + 1, LCA(x + 1, y + 1));
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
