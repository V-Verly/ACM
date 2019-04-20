#include <bits/stdc++.h>

using namespace std;

int a, b, num[20], dp[20][12];

int dfs(int len, int last, bool flag)
{
    if(len == 0) return 1;
    if(!flag && last>=0 && dp[len][last]) return dp[len][last];
    int p, cnt = 0, lim = flag ? num[len] : 9;
    for(int i = 0; i <= lim; i++)
    {
        if(abs(i - last) < 2) continue;
        cnt += dfs(len - 1, (i == 0 && last == -10) ? last : i, flag && i == lim);
    }
    return (flag || last < 0) ? cnt : dp[len][last] = cnt;
}

int solve(int x)
{
    memset(num, 0, sizeof num);
    int len = 0;
    while(x)
    {
        num[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, -10, true);
}

int main()
{
    scanf("%d%d", &a, &b);
    printf("%d\n", solve(b) - solve(a - 1));
    return 0;
}
