#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%d", &n);
        double p = 0;
        for(int i = 1; i <= n; i ++) p += 1.0 / i;
        p *= n;
        printf("Case %d: %f\n", _, p);
    }
    return 0;
}
