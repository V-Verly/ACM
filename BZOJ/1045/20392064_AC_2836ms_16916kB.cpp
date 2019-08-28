#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
ll a[maxn], c[maxn], ave;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
        ave += a[i];
    }
    ave /= n;
    for(int i = 2; i <= n; i ++) c[i] = c[i - 1] + a[i] - ave;
    sort(c + 1, c + n + 1);
    ll ans = 0, mid = c[(n >> 1) + 1];
    for(int i = 1; i <= n; i ++) ans += abs(c[i] - mid);
    printf("%lld\n", ans);
    return 0;
}
