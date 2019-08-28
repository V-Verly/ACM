#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10;
double dp[maxn], P[maxn];
int w[maxn];

int main()
{
    int T, n;
    double p;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%lf%d", &p, &n);
        int m = 0;
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i ++) scanf("%d%lf", &w[i], &P[i]), m += w[i];
        dp[0] = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = m; j >= w[i]; j --)
                dp[j] = max(dp[j], dp[j - w[i]] * (1 - P[i]));
        int res = 0;
        for(int i = 0; i <= m; i ++) if((1 - dp[i]) <= p) res = i;
        printf("Case %d: %d\n", _, res);
    }
    return 0;
}
