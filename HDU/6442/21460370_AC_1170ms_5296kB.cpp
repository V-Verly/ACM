#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;
int sq[maxn]; ll A, B, u, n, mod;

ll qp(ll A, ll u, ll n)
{
    ll X = 1, Y = 0;
    for(; n; n >>= 1)
    {
        if(n & 1)
        {
            ll Xn, Yn;
            Xn = (X * A % mod + Y * u % mod * B % mod) % mod;
            Yn = (X * u % mod + Y * A % mod) % mod;
            X = Xn, Y = Yn;
        }
        ll tmp = A;
        A = (A * A % mod + u * u % mod * B % mod) % mod;
        u = 2ll * tmp % mod * u % mod;
    }
    return Y;
}

int main()
{
    int _;
    for(int i = 1; i <= 1000; i ++)
        for(int j = i * i; j <= (int) 1e6; j += i * i) sq[j] = i;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%lld%lld%lld%lld", &A, &B, &n, &mod);
        u = sq[B];
        B = B / u / u;
        printf("1 %lld %lld\n", qp(A, u, n), B);
    }
    return 0;
}
