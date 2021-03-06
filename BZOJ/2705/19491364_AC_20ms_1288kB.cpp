#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll phi(ll n)
{
    ll ans = n;
    for(ll i = 2; i * i <= n; i++) if(n % i == 0)
    {
        ans = ans / i * (i - 1);
        while(n % i == 0) n /= i;
    }
    if(n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main()
{
    ll n, ans = 0;
    scanf("%lld", &n);
    for(ll i = 1; i * i <= n; i++) if(n % i == 0)
    {
        ans += i * phi(n / i);
        if(i * i < n) ans += n / i * phi(i);
    }
    printf("%lld\n", ans);
    return 0;
}
