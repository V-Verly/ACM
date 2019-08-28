#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

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
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
    for(int i = n; i >= 1; i--) ++sa[i], rk[i] = rk[i - 1];
}

char a[maxn], b[maxn];
int lena, lenb;

int main()
{
    while(scanf("%s%s", a, b) != EOF)
    {
        n = 0, lena = strlen(a), lenb = strlen(b);
        for(int i = 0; i < lena; i ++) s[n ++] = a[i]; s[n ++] = '$';
        for(int i = 0; i < lenb; i ++) s[n ++] = b[i]; s[n] = 0;
        build_sa(n + 1, 130);
        getHeight();
        int ans = 0;
        for(int i = 2; i <= n; i ++)
        {
            int pos1 = sa[i - 1], pos2 = sa[i], len = height[i];
            if(pos1 > pos2) swap(pos1, pos2);
            if(pos1 < lena && pos2 > lena)
            {
                len = min(len, lena - pos1 + 1);
                ans = max(len, ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
