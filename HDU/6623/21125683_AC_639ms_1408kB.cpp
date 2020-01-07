#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e4 + 10;
int prime[maxn], cnt;
bool vis[maxn];

void Euler_Sieve()
{
    for(int i = 2; i < maxn; i ++)
    {
        if(!vis[i]) vis[i] = i, prime[++ cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] < maxn; j ++)
        {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

bool check2(ll val)
{
    ll t = ll(sqrt(val + 0.5) + 0.5);
    return (t * t == val);
}

bool check3(ll val)
{
    ll t = ll(pow(val + 0.5, 1.0 / 3) + 0.5);
    return (t * t * t == val);
}

bool check4(ll val)
{
    ll t = ll(sqrt(sqrt(val + 0.5)) + 0.5);
    return (t * t * t * t == val);
}

int main()
{
    int t; ll n;
    scanf("%d", &t);
    Euler_Sieve();
    while(t --)
    {
        ll ans = 0x3f3f3f3f;
        scanf("%lld", &n);
        for(int i = 1; i <= cnt; i ++)
        {
            int x = prime[i];
            if(x > n) break;
            if(n % x == 0)
            {
                int tmp = 0;
                while(n % x == 0) n /= x, tmp ++;
                ans = min(ans, 1ll * tmp);
                if(ans == 1) { n = 1; break; }
            }
        }
        if(n == 1) printf("%lld\n", ans);
        else if(check4(n)) puts("4");
        else if(check3(n)) puts("3");
        else if(check2(n)) puts("2");
        else puts("1");
    }
    return 0;
}
