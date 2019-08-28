#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%d", &n);
        double p = 1; int res;
        for(int i = 1; i <= n; i ++)
        {
            p = p * (n - i) / n;
            if(p <= 0.5) { res = i; break; }
        }
        printf("Case %d: %d\n", _, res);
    }
    return 0;
}
