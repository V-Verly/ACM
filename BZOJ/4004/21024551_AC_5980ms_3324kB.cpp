#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
 
struct Z { ll a[505]; int val; } z[505];
int b[505];
 
bool cmp(const Z &a, const Z &b) { return a.val < b.val; }
 
int inv(int a, int n = mod - 2)
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
    int n, m, cnt = 0, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%lld", &z[i].a[j]);
    for(int i = 1; i <= n; i ++) scanf("%d", &z[i].val);
    sort(z + 1, z + n + 1, cmp);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++) if(z[i].a[j])
        {
            if(!b[j])
            {
                b[j] = i;
                cnt ++, ans += z[i].val;
                break;
            }
            else
            {
                int t = 1ll * z[i].a[j] * inv(z[b[j]].a[j]) % mod;
                for(int k = j; k <= m; k ++)
                    z[i].a[k] = (z[i].a[k] - 1ll * t * z[b[j]].a[k] % mod + mod) % mod;
            }
        }
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}