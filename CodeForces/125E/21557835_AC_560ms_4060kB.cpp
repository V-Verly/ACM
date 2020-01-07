#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5000 + 10;
const int maxm = 1e5 + 10;
struct edge {
    int u, v, w, col, id;
    bool operator < (const edge &e) const
    {
        return w == e.w ? col < e.col : w <e.w;
    }
}es[maxm];
int n, m, k, pre[maxn];
int tot, cnt;

int Find(int x) { return x == pre[x] ? x :pre[x] = Find(pre[x]); }

bool Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if(fx == fy) return false;
    pre[fx] = fy;
    return true;
}

bool vis[maxm];

bool check(int x)
{
    for(int i = 1; i <= n; i ++) pre[i] = i;
    for(int i = 1; i <= m; i ++) vis[i] = 0;
    for(int i = 1; i <= m; i ++) if(!es[i].col) es[i].w += x;
    sort(es + 1, es + 1 + m);
    tot = 0, cnt = 0;
    for(int i = 1; i <= m; i ++)
    {
        int u = es[i].u, v = es[i].v;
        if(Union(u, v))
        {
            tot ++;
            //tot += es[i].w;
            if(!es[i].col) cnt ++;
            vis[es[i].id] = 1;
        }
    }
    for(int i = 1; i <= m; i ++) if(!es[i].col) es[i].w -= x;
    return cnt >= k;

}

signed main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    int sum = 0;
    for(int i = 1; i <= m; i ++)
    {
        scanf("%lld%lld%lld", &es[i].u, &es[i].v, &es[i].w);
        es[i].w *= m;
        if(es[i].u == 1 || es[i].v == 1) es[i].col = 0, sum ++, es[i].w += i;
        else es[i].col = 1;
        es[i].id = i;
    }
    if(sum < k) return 0 * puts("-1");
    int l = -1e10, r = 1e10, mid, flag = 0, p = -1;
    while(l <= r)
    {
        mid = l + r >> 1;
        if(check(mid))
        {
            l = mid + 1, p = mid;
            flag = 1;
        }
        else r = mid - 1;
    }
    check(p);
    if(cnt > k) return 0 * puts("-1");
    printf("%lld\n", n - 1);
    for(int i = 1; i <= m; i ++) if(vis[i]) printf("%lld ", i);
    return 0;
}
