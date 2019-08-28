#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e4 + 10;
 
vector<int> edge[maxn];
 
int n, dep[maxn], fa[maxn][20]; ll a[maxn];
 
struct LinearBasis
{
    ll d[64], tot;
 
    LinearBasis()
    {
        memset(d, 0, sizeof d);
        tot = 0;
    }
 
    void ins(ll x)
    {
        for(int i = 63; i >= 0; i --) if((x >> i) & 1)
        {
            if(d[i]) x ^= d[i];
            else { d[i] = x; tot ++; return; }
        }
    }
 
    ll max_xor()
    {
        ll ans = 0;
        for(int i = 63; i >= 0; i --) if((ans ^ d[i]) > ans) ans ^= d[i];
        return ans;
    }
 
    void Merge(LinearBasis &a) { for(int i = 63; i >= 0; i --) if(a.d[i]) ins(a.d[i]); }
}L[maxn][20];
 
LinearBasis merge(const LinearBasis &a, const LinearBasis &b)
{
    LinearBasis res = a;
    for(int i = 63; i >= 0; i --) if(b.d[i]) res.ins(b.d[i]);
    return res;
}
 
void dfs(int u, int pre)
{
    dep[u] = dep[pre] + 1, fa[u][0] = pre;
    L[u][0].ins(a[pre]); L[u][0].ins(a[u]);
    for(int i = 1; (1 << i) <= n; i ++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        L[u][i].Merge(L[u][i - 1]);
        L[u][i].Merge(L[fa[u][i - 1]][i - 1]);
    }
    for(int i = 0; i < edge[u].size(); i ++) {int v = edge[u][i]; if(v != pre) dfs(v, u); }
}
 
LinearBasis LCA(int u, int v)
{
    LinearBasis res;
    if(dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for(int i = 0; (1 << i) <= d; i ++) if((1 << i) & d) res.Merge(L[u][i]), u = fa[u][i];
    if(u == v) { res.ins(a[v]); return res; }
    for(int i = 19; i >= 0; i --) if(fa[u][i] != fa[v][i]) res.Merge(L[u][i]), res.Merge(L[v][i]), u = fa[u][i], v = fa[v][i];
    res.Merge(L[u][0]), res.ins(a[v]);
    return res;
}
 
int main()
{
    int q, u, v;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for(int i = 1; i < n; i ++)
    {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    while(q --)
    {
        scanf("%d%d", &u, &v);
        LinearBasis ans = LCA(u, v);
        printf("%lld\n", ans.max_xor());
    }
    return 0;
}