#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20000 + 10;
const int inf = 0x3f3f3f3f;

int a[maxn], s[maxn];
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

bool check(int k)
{
    int mx = -inf, mn = inf;
    for(int i = 2; i <= n; i ++)
    {
        if(height[i] >= k)
        {
            mn = min(mn, min(sa[i], sa[i - 1]));
            mx = max(mx, max(sa[i], sa[i - 1]));
            if(mx - mn > k) return true;
        }
        else mx = -inf, mn = inf;
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        n --;
        for(int i = 0; i < n; i ++) s[i] = a[i + 1] - a[i] + 88;
        s[n] = 0;
        build_sa(n + 1, 176);
        getHeight();
        int l = 0, r = n >> 1, ans = -1;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(check(mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        if(ans < 4) ans = -1;
        printf("%d\n", ans + 1);
    }
    return 0;
}
