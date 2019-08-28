#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int qp(int a, int n, int mod)
{
    long long ans = 1, base = a % mod;
    while(n)
    {
        if(n & 1) (ans *= base) %= mod;
        (base *= base) %= mod;
        n >>= 1;
    }
    return ans;
}
 
int inv(int a, int p) { return qp(a, p - 2, p); }
 
int BSGS(int a, int b, int p)
{
    map<int, int> hash;
    b %= p;
    int t = (int)sqrt(p) + 1;
    for(int j =0; j < t; j ++)
    {
        int val = 1ll * b * qp(a, j, p) % p;
        hash[val] = j;
    }
    a = qp(a, t, p);
    if(a == 0) return b == 0 ? 1 : -1;
    for(int i = 1; i <= t; i ++)
    {
        int val = qp(a, i, p);
        int j = hash.find(val) == hash.end() ? -1 : hash[val];
        if(j >= 0 && i * t - j >= 0) return i * t - j;
    }
    return -1;
}
 
signed main()
{
    int _, p, a, b, x, t;
    scanf("%lld", &_);
    while(_ --)
    {
        scanf("%lld%lld%lld%lld%lld", &p, &a, &b, &x, &t);
        if(x == t) { puts("1"); continue; }
        if(a == 0) { printf("%d\n", t == b ? 2 : -1); continue; }
        else if(a == 1) {printf("%lld\n", b ? ((((t - x) % p + p) % p) * inv(b, p) % p + 1) : -1); continue; }
        int tmp = b * inv(a - 1, p) % p;
        int y = (t + tmp) % p * inv((x + tmp) % p, p) % p * a % p;
        int ans = BSGS(a, y, p);
        printf("%lld\n", ans);
    }
    return 0;
}