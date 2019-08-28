#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int n;
inline int getpos(int x, int lasans) { return (x ^ lasans) % n + 1; }

struct LinearBasis
{
    int f[30], g[30];

    void ins(int x, int pos)
    {
        for(int i = 29; ~i; i --)
        {
            if((x >> i) & 1)
            {
                if(f[i])
                {
                    if(g[i] <= pos) { x ^= f[i]; f[i] ^= x; swap(g[i], pos); }
                    else x ^= f[i];
                }
                else { f[i] = x; g[i] = pos; break; }
            }
        }
    }

    int query(int l)
    {
        int res = 0;
        for(int i = 29; ~i; i --) if(g[i] >= l) res = max(res, res ^ f[i]);
        return res;
    }
}base[maxn];

int main()
{
    int t, q, op, l, r, x;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &x);
            base[i] = base[i - 1];
            base[i].ins(x, i);
        }
        int ans = 0;
        while(q --)
        {
            scanf("%d", &op);
            if(op == 0)
            {
                scanf("%d%d", &l, &r);
                l = getpos(l, ans), r = getpos(r, ans);
                if(l > r) swap(l, r);
                printf("%d\n", ans = base[r].query(l));
            }
            else
            {
                scanf("%d", &x); n ++;
                base[n] = base[n - 1], base[n].ins(x ^ ans, n);
            }
        }
    }
    return 0;
}
