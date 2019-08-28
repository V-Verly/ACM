#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], b[maxn];

int solve(int *a, int *b)
{
    int ans = 0;
    int l = 1, r = n, x = 1, y = n;
    while(l <= r)
    {
        if(a[l] > b[x]) ans += 2, l ++, x ++;
        else if(a[r] > b[y]) ans += 2, r --, y --;
        else
        {
            if(a[l] == b[y]) ans ++;
            l ++, y --;
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    printf("%d %d\n", solve(a, b), 2 * n - solve(b, a));
    return 0;
}
