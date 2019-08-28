#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 10;

char s[maxn], b[maxn];
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

int rmax[maxn], nex[maxn];

void getNext()
{
    int n = strlen(b), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || b[i] == b[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

void KMP()
{
    int n = strlen(s), m = strlen(b), i = 0, j = 0, pos = 1;
    getNext();
    while(i < n)
    {
        if(j == -1 || s[i] == b[j]) i ++, j ++;
        else j = nex[j];
        if(j == m)
        {
            for(int p = pos; p <= i - m + 1; p ++) rmax[p] = i - p;
            j = nex[j], pos = i - m + 2;
        }
    }
    while(pos <= n) rmax[pos] = n - pos + 1, pos ++;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        scanf("%s%s", s, b);
        n = strlen(s);
        KMP();
        build_sa(n + 1, 130);
        getHeight();
        long long res = 0;
        for(int i = 1; i <= n; i ++) res += rmax[sa[i]] - min(rmax[sa[i]], height[i]);
        printf("Case %d: %lld\n", _, res);
    }
    return 0;
}
