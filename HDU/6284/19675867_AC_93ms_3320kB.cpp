#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn], l[maxn], r[maxn];
int dp[maxn], sec[maxn];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i <= n; i ++) l[i] = r[i] = sec[i] = 0;
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        int st = 1, len = 0;
        while(a[st] == 0 && st <= n) st ++;
        if(st <=n) dp[++ len] = a[st];
        l[st] = 1;
        for(int i = st + 1; i <= n; i ++) if(a[i])
        {
            int pos = lower_bound(dp + 1, dp + len + 1, a[i]) - dp;
            dp[pos] = a[i];
            l[i] = pos;
            if(pos == len + 1) len ++;
        }

        st = n, len = 0;
        while(a[st] == 0 && st) st --;
        if(st) dp[++ len] = -a[st];
        r[st] = 1;
        for(int i = st - 1; i > 0; i --) if(a[i])
        {
            int pos = lower_bound(dp + 1, dp + len + 1, -a[i]) - dp;
            dp[pos] = -a[i];
            r[i] = pos;
            if(pos == len + 1) len ++;
        }

        for(int i = 0; i <= n; i ++) dp[i] = 0;
        int cur = n;
        while(cur > 0)
        {
            int tmp = cur;
            for(; cur > 0; cur --)
            {
                if(!a[cur]) {dp[0] = n + 1; break; }
                int u = len - l[cur];
                if(dp[u] - 1 > a[cur])
                {
                    sec[a[cur] + 1] ++;
                    sec[dp[u]] --;
                }
            }
            for(int i = tmp; i > cur; i --) if(dp[r[i]] < a[i]) dp[r[i]] = a[i];
            if(dp[len] - 1 > a[cur] && cur)
            {
                sec[a[cur] + 1] ++;
                sec[dp[len]] --;
            }
            cur --;
        }
        for(int i = 1; i <= n; i ++) sec[i] += sec[i - 1];
        long long ans = 0;
        for(int i = 1; i <= n; i ++) ans += 1ll * i * (sec[i] ? len + 1 : len);
        printf("%lld\n", ans);
    }
    return 0;
}
