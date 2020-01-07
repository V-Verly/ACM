#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cost(ll a, ll b, ll len)
{
    ll bb = b;
    if(b >= a) bb = a;
    ll res = (len / 2) * bb * 2 + (len % 2) * b;
    return res;
}

ll cal(ll a, ll b, ll x, ll y)
{
    x = abs(x), y = abs(y);

    ll res = cost(a, b, x) + cost(a, b, y), p = min(x, y);
    res = min(res, p * a + cost(a, b, max(x, y) - min(x, y)));
    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        ll a, b, x, y;
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        ll res = cal(a, b, x, y);
        res = min(res, cal(a, b, x - 1, y));
        res = min(res, cal(a, b, x - 1, y + 1));
        res = min(res, cal(a, b, x, y + 1));
        printf("%lld\n", res);
    }
    return 0;
}
