#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;

char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], n;

void build_sa(int n, int m)
{
    int *x = t, *y = t2;
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for(int i = n - k; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 0; i < m; i++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if(p >= n) break;
        m = p;
    }
}

int rk[maxn], height[maxn];

void getHeight()
{
    for(int i = 1; i <= n; i++) rk[sa[i]] = i;
    for(int i = 0, k = 0; i < n; i++)
    {
        if(k) k--;
        int j = sa[rk[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

int main()
{
    while(scanf("%s", s) != EOF && s[0] != '#')
    {
        n = strlen(s);
        build_sa(n + 1, 130);
        getHeight();
        long long res = 0;
        for(int i = 1; i <= n / 2; i ++)
        {
            int l = inf, r = 0;
            for(int j = 2; j <= n; j ++)
            {
                if(height[j] >= i)
                {
                    l = min(l, min(sa[j - 1], sa[j]));
                    r = max(r, max(sa[j - 1], sa[j]));
                }
                else
                {
                    if(r - l >= i) res ++;
                    l = inf, r = 0;
                }
            }
            if(r - l >= i) res ++;
        }
        printf("%lld\n", res);
    }
    return 0;
}
