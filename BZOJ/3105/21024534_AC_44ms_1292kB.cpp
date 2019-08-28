#include <bits/stdc++.h>

using namespace std;

int d[32];

bool ins(int x)
{
    for(int i = 31; i >= 0; i --)
    {
        if((x >> i) & 1)
        {
            if(d[i]) x ^= d[i];
            else { d[i] = x; return true; }
        }
    }
    return false;
}

int main()
{
    int n, a[105];
    long long res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = n - 1; i >= 0; i --) if(!ins(a[i])) res += a[i];
    printf("%lld\n", res);
    return 0;
}
