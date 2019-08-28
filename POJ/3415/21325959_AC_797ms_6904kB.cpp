#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 2e5 + 10;

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

char a[maxn];
int st[maxn], cnt[maxn], top = 0;

int main()
{
    int k;
    while(scanf("%d", &k) != EOF && k)
    {
        n = 0;
        scanf("%s", a);
        for(int i = 0; a[i]; i ++) s[n ++] = a[i];
        int len = n; s[n ++] = '$';
        scanf("%s", a);
        for(int i = 0; a[i]; i ++) s[n ++] = a[i];
        s[n] = 0;
        build_sa(n + 1, 130);
        getHeight();
        long long res = 0, sum = 0, num = 0; top = 0;
        for(int i = 2; i<= n; i ++)
        {
            if(height[i] < k) { top = 0, sum = 0; continue; }
            int num = 0;
            while(top && st[top] > height[i])
            {
                sum -= 1ll * (st[top] - k + 1) * cnt[top];
                sum += 1ll * (height[i] - k + 1) * cnt[top];
                num += cnt[top --];
            }
            st[++ top] = height[i];
            if(sa[i - 1] > len) sum += height[i] - k + 1, cnt[top] = num + 1;
            else cnt[top] = num;
            if(sa[i] <= len) res += sum;
        }
        sum = 0, top = 0;
        for(int i = 2; i<= n; i ++)
        {
            if(height[i] < k) { top = 0, sum = 0; continue; }
            int num = 0;
            while(top && st[top] > height[i])
            {
                sum -= 1ll * (st[top] - k + 1) * cnt[top];
                sum += 1ll * (height[i] - k + 1) * cnt[top];
                num += cnt[top --];
            }
            st[++ top] = height[i];
            if(sa[i - 1] <= len) sum += height[i] - k + 1, cnt[top] = num + 1;
            else cnt[top] = num;
            if(sa[i] > len) res += sum;
        }
        printf("%lld\n", res);
    }
    return 0;
}
