#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
    {
        int p = a[i], q = a[p];
        if(i == a[q]) return 0 * puts("YES");
    }
    puts("NO");
    return 0;
}
