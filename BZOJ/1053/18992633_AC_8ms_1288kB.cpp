#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, ans = 1, num = 1;
int p[20] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void dfs(int k, ll now, int cnt, int last)
{
    if(k == 12)
    {
        if(now > ans && cnt > num || now <= ans && cnt >= num) ans = now, num = cnt;
        return ;
    }
    int r = 1;
    for(int i = 0; i <= last; i++)
    {
        dfs(k + 1, now * r, cnt * (i + 1), i);
        r *= p[k];
        if(now * r > n) break;
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1, 1, 1, 20);
    printf("%d\n", ans);
    return 0;
}
