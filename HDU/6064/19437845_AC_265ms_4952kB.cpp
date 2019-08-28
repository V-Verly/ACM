#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 998244353;

ll Fac(ll x)
{
    ll res = 1;
    for(int i = 2; i <= x; i++) (res *= i) %= mod;
    return res;
}

ll inv(ll a, ll n = mod - 2)
{
    ll ans = 1, base = a;
    for(; n; n >>= 1, (base *= base) %= mod) if(n & 1) (ans *= base) %= mod;
    return ans;
}

struct Matrix
{
    ll a[505][505];
    ll det(int n)
    {
        ll ans = 1;
        for(int k = 0; k < n; k++)
        {
        	int pos = -1;
        	for(int i = k; i < n; i++)
        		if(a[i][k]) {pos = i; break; }
        	if(pos == -1) return 0;
        	if(pos != k) for(int j = k; j < n; j++) swap(a[pos][j], a[k][j]);
        	for(int i = k + 1; i < n; i++)
        		if(a[i][k])
        		{
        			(ans *= inv(a[k][k])) %= mod;
        			for(int j = k + 1; j < n; j++)
        				a[i][j] = (a[i][j] * a[k][k] % mod - a[k][j] * a[i][k] % mod + mod) % mod;
        			a[i][k] = 0;
        		}
        }
        for(int i = 0; i < n; i++) (ans *= a[i][i]) %= mod;
        return ans;
    }
}mat;

ll solve(int n)
{
    ll D[505][505], res = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lld", &D[i][j]), mat.a[i][j] = -D[i][j], (res *= inv(Fac(D[i][j]))) %= mod;

    for(int i = 0; i < n; i++)
    {
        int in = 0, out = 0;
        for(int j = 0; j < n; j++) in += D[j][i], out += D[i][j];
        if(in != out) return 0;
        mat.a[i][i] += in;
        if(!i) (res *= Fac(in)) %= mod;
        else (res *= Fac(in - 1)) %= mod;
    }
    (res *= mat.det(n - 1)) %= mod;
    return res;
}

int main()
{
    int n, _ = 0;
    while(scanf("%d", &n) != EOF)
        printf("Case #%d: %lld\n", ++_, solve(n));
    return 0;
}