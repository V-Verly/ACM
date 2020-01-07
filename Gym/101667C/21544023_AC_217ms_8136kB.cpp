#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int in[maxn], ans[maxn];

int dfs(int u)
{
    if(ans[u]) return ans[u];
    ans[u] = 1;
    for(auto v : G[u]) if(in[v] > in[u]) ans[u] = max(ans[u], dfs(v) + 1);
    return ans[u];
}

int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        in[u] ++;
        in[v] ++;
    }
    int res = 0;
    for(int i = 0; i < n; i ++) res = max(res, dfs(i));
    printf("%d\n", res);
    return 0;
}
