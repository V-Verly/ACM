#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll qp(ll a, ll n)
{
    ll ans = 1, base = a;
    for(; n; base *= base, n >>= 1) if(n & 1) ans *= base;
    return ans;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n != -1)
    {
        if(n == 0) { puts("0"); continue; }
        ll ans = 0;
        for(int i = 1; i <= n; i ++) ans += qp(3, gcd(i, n));
        if(n & 1) ans += n * qp(3, n / 2 + 1);
        else ans += n / 2 * qp(3, n / 2 + 1) + n / 2 * qp(3, n / 2);
        printf("%lld\n", ans / (2 * n));
    }
    return 0;
}
