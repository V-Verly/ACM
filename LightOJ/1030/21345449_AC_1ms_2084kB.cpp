#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n;
    double f[105], g[105];
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        printf("Case %d: ", _);
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%lf", &g[i]);
        for(int i = n; i >= 1; i --)
        {
            f[i] = g[i];
            for(int j = 1; j <= min(n - i, 6); j ++)
                f[i] += f[i + j] / min(n - i, 6);
        }
        printf("%f\n", f[1]);
    }
    return 0;
}
