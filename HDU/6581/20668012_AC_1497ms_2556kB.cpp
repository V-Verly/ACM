#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int l[maxn], s[maxn], v[maxn];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i <= n; i ++) scanf("%d", &l[i]);
        for(int i = 0; i <= n; i ++) scanf("%d", &s[i]);
        for(int i = 0; i <= n; i ++) scanf("%d", &v[i]);
        long long L = 0;
        double ans = 1.0 * s[0] / v[0], tm;
        for(int i = 1; i <= n; i ++)
        {
            L += l[i];
            tm = 1.0 * (L + s[i]) / v[i];
            ans = max(ans, tm);
        }
        printf("%f\n", ans);
    }
    return 0;
}
