#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
vector<pair<int, long long> > edge[maxn];
int a[maxn], tot;

void dfs(int u, ll d)
{
    if(a[u] < d) return;
    tot ++;
    for(auto v : edge[u]) dfs(v.first, max(d + v.second, 0ll));
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 2; i <= n; i ++)
    {
        int v, w;
        scanf("%d%d", &v, &w);
        edge[v].push_back({i, w});
    }
    dfs(1, 0);
    printf("%d\n", n - tot);
    return 0;
}
