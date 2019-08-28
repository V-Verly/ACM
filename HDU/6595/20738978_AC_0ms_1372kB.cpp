#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;

ll inv(ll a, ll n = mod - 2)
{
    ll ans = 1, base = a;
    while(n)
    {
        if(n & 1) (ans *= base) %= mod;
        (base *= base) %= mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    long long n;
    while(scanf("%lld", &n) != EOF)
        printf("%lld\n", (n + 1) * (n - 1) % mod * inv(9) % mod);
    return 0;
}