#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, m, rt;
int deg[maxn], dep[maxn], a[maxn], fa[maxn][20];
vector<int> G[maxn], revG[maxn];

void Toposort()
{
    queue<int> que;
    rt = n + 1;
    for(int i = 1; i <= n; i ++) if(!deg[i]) que.push(i), revG[rt].push_back(i), G[i].push_back(rt);
    int tot = 0;
    while(!que.empty())
    {
        int u = que.front(); que.pop();
        a[++ tot] = u;
        for(int v : revG[u]) if((--deg[v]) == 0) que.push(v);
    }
}

int LCA(int u, int v)
{
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i --) if(dep[v] > dep[u] && dep[fa[v][i]] >= dep[u]) v = fa[v][i];
    for(int i = 19; i >= 0; i --) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return u == v ? u : fa[u][0];
}

int main()
{
    int t, u, v;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n + 1; i ++)
        {
            G[i].clear(); revG[i].clear();
            deg[i] = dep[i] = 0;
        }
        while(m --)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v); revG[v].push_back(u);
            deg[u] ++;
        }
        Toposort();
        dep[rt] = 1;
        for(int i = 1; i <= n; i ++)
        {
            int u = a[i], f = -1;
            for(int v : G[u]) f = ((f == -1) ? v : LCA(f, v));
            dep[u] = dep[f] + 1, fa[u][0] = f;
            for(int i = 1; i <= 19; i ++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        int q;
        scanf("%d", &q);
        while(q --)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", dep[u] + dep[v] - dep[LCA(u, v)] - 1);
        }
    }
    return 0;
}