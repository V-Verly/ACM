#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        printf("Case %d: ", _);
        int sum = 0, t = 0;
        scanf("%d", &n);
        for(int i = 0, x; i < n; i ++)
        {
            scanf("%d", &x);
            sum += abs(x), t += x > 0;
        }
        int g = __gcd(sum, t);
        if(!t) puts("inf");
        else printf("%d/%d\n", sum / g, t / g);
    }
    return 0;
}
