#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 10;

int a[maxn];

int main()
{
    int n, m, u, v, w, res = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    while(m --)
    {
        scanf("%d%d", &u, &v);
        res += min(a[u], a[v]);
    }
    printf("%d\n", res);
    return 0;
}
