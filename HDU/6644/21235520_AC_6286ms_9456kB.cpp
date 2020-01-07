#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 5e4 + 10;
const int mod = 1e9 + 7;

int pos[maxn];
ll val[maxn], modVal[25][maxn], dp[maxn][25];
char s[maxn];

int main()
{
    int _, n, m, q;
    scanf("%d", &_);
    val[0] = 1;
    for(int i = 1; i < maxn; i ++) val[i] = val[i - 1] * 10 % mod;
    for(int i = 2; i <= 20; i ++)
    {
        modVal[i][0] = 1;
        for(int j = 1; j < maxn; j ++) modVal[i][j] = modVal[i][j - 1] * 10 % i;
    }
    while(_ --)
    {
        scanf("%d%d%d", &n, &m, &q);
        scanf("%s", s);
        ll resA = 0, resMod = 0, cnt = 0;
        for(int i = n - 1; i >= 0; i --)
        {
            if(s[i] != '?')
            {
                (resA += val[n - 1 - i] * (s[i] - '0') % mod) %= mod;
                (resMod += modVal[m][n - 1 - i] * (s[i] - '0') % m) %= m;
            }
            else pos[++ cnt] = n - 1 - i;
        }
        for(int i = 0; i <= m; i ++) dp[0][i] = 0;
        dp[0][resMod] = 1;
        for(int i = 1; i <= cnt; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                dp[i][j] = 0;
                for(int k = 0; k <= 9; k ++) dp[i][j] += dp[i - 1][((j - modVal[m][pos[i]] * k % m) % m + m) % m];
            }
            if(dp[i][0] >= (ll)1e18) cnt = i;
        }
        while(q --)
        {
            ll k, ans = resA, x = 0;
            scanf("%lld", &k);
            if(k > dp[cnt][0]) { puts("-1"); continue; }
            int p = cnt;
            while(k)
            {
                for(int i = p; i >= 0; i --) if(dp[i][x] >= k) p = i;
                if(p == 0) break;
                for(int i = 0; i <= 9; i ++)
                {
                    ll tmp = dp[p - 1][((x - modVal[m][pos[p]] * i % m) % m + m) % m];
                    if(tmp < k) k -= tmp;
                    else
                    {
                        (ans += val[pos[p]] * i % mod) %= mod;
                        x = ((x - modVal[m][pos[p]] * i % m) % m + m) % m;
                        break;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}