#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
double dp[maxn];

int main()
{
    int T, n;
    for(int i = 2; i < maxn; i ++)
    {
        double num = -1, res = 0;
        for(int j = 1; j * j <= i; j ++)
        {
            if(i % j == 0)
            {
                num ++;
                res += 1 + dp[j];
                if(i / j != j)
                {
                    num ++;
                    res += 1 + dp[i / j];
                }
            }
        }
        dp[i] = res / num;
    }
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%d", &n);
        printf("Case %d: %f\n", _, dp[n]);
    }
    return 0;
}
