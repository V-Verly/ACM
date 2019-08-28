#include <bits/stdc++.h>

using namespace std;

const int maxn = 20000 + 10;

char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], n;

//build_sa(n + 1, 130), sa, rk, height下标从1开始
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
    for(int i = n; i >= 1; i--) ++sa[i], rk[i] = rk[i - 1];
}

char x[maxn], y[maxn], z[maxn];
int lena, lenb, lenc;

int getid(int pos)
{
    if(pos < lena) return 0;
    pos = pos - lena - 1;
    if(pos < lenb) return 1;
    return 2;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%s%s%s", x, y, z);
        n = 0, lena = strlen(x), lenb = strlen(y), lenc = strlen(z);
        for(int i = 0; x[i]; i ++) s[n ++] = x[i]; s[n ++] = '#';
        for(int i = 0; y[i]; i ++) s[n ++] = y[i]; s[n ++] = '$';
        for(int i = 0; z[i]; i ++) s[n ++] = z[i]; s[n] = 0;
        build_sa(n + 1, 130);
        getHeight();
        int res = 0;
     //   for(int i = 1; i <= n; i ++) printf("%s\n", s + sa[i] - 1);
        for(int i = 4; i <= n; i ++)
        {
            int p1 = getid(sa[i - 2]);
            int p2 = getid(sa[i - 1]);
            int p3 = getid(sa[i]);
            if(p1 == p3 || p2 == p3 || p1 == p2) continue;
            res = max(res, min(height[i], height[i - 1]));
        }
        printf("Case %d: %d\n", _, res);
    }
    return 0;
}
