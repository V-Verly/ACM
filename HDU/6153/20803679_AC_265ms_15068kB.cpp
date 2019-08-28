#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
typedef long long ll;

char a[maxn], b[maxn];
int nex[maxn];

void getNext()
{
    int n = strlen(a), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || a[i] == a[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

ll dp[maxn];

void KMP()
{
    int n = strlen(a), m = strlen(b);
    getNext();
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(i == -1 || a[i] == b[j]) i ++, j ++;
        else i = nex[i];
        if(~i) dp[i] ++;
        if(i == n) i = nex[i];

    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%s%s", b, a);
        int n = strlen(a), m = strlen(b);
        reverse(a, a + n);
        reverse(b, b + m);
        for(int i = 0; i <= n; i ++) dp[i] = 0;
        ll ans = 0;
        KMP();
        for(int i = n; i > 0; i --)
        {
            if(~nex[i]) dp[nex[i]] += dp[i];
            (ans += dp[i] * i % mod) %= mod;
        }
        printf("%lld\n", ans);

    }
    return 0;
}
