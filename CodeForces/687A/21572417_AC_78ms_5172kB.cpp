#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int col[maxn];

vector<int> ans[2];

void dfs(int u, int color)
{
    col[u] = color;
    ans[color].push_back(u);
    for(auto v : G[u])
    {
        if(col[v] == -1) dfs(v, 1 ^ color);
        else if(col[v] == col[u]) { puts("-1"), exit(0); }
    }
}

int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    memset(col, 0xff, sizeof col);
    while(m --)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) if(col[i] == -1) dfs(i, 0);
    printf("%d\n", ans[0].size());
    for(auto i : ans[0]) printf("%d ", i);
    printf("\n%d\n", ans[1].size());
    for(auto i : ans[1]) printf("%d ", i);
    return 0;
}
