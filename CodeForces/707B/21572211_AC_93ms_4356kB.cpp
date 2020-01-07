#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct edge{ int u, v, w; }es[maxn];
map<int, int> mp;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
    for(int i = 1, x; i <= k; i ++)
        scanf("%d", &x), mp[x] = 1;
    int res = 0x3f3f3f3f;
    for(int i = 1; i <= m; i ++)
    {
        if(mp[es[i].u] && !mp[es[i].v]) res = min(res, es[i].w);
        if(mp[es[i].v] && !mp[es[i].u]) res = min(res, es[i].w);
    }
    if(res == 0x3f3f3f3f) res = -1;
    printf("%d\n", res);
    return 0;
}
