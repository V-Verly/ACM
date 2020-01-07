#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

vector<int> G[maxn], rG[maxn];
pair<int, int> edge[maxn];
bool vis[maxn];
map<pair<int, int>, int> mp;

void dfs(int u)
{
    vis[u] = true;
    for(auto v : G[u]) if(!vis[v]) mp[make_pair(u, v)] = 1, dfs(v);
}

void dfs1(int u)
{
    vis[u] = true;
    for(auto v : rG[u]) if(!vis[v]) mp[make_pair(v, u)] = 1, dfs1(v);
}

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int n, m, u, v;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) G[i].clear(), rG[i].clear(), vis[i] = false;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            rG[v].push_back(u);
            edge[i] = make_pair(u, v);
        }
        mp.clear();
        dfs(1);
        for(int i = 1; i <= n; i ++) vis[i] = false;
        dfs1(1);
        for(int i = 1, cnt = 0; i <= m && cnt < m - 2 * n; i ++)
            if(!mp.count(edge[i])) printf("%d %d\n", edge[i].first, edge[i].second), cnt ++;
    }
    return 0;
}
