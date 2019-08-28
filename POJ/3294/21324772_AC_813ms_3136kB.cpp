#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10;

int s[maxn];
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
int m, len[105], pos[maxn], cur;
bool vis[105];

inline int getid(int x) { for(int i = 1; i <= m; i ++) if(x >= len[i - 1] && x <= len[i]) return i; }

bool check(int x)
{
    memset(vis, false, sizeof vis);
    int cnt = 0; cur = 0;
    for(int i = 2; i <= n; i ++)
    {
        if(height[i] >= x)
        {
            int pos1 = getid(sa[i - 1]), pos2 = getid(sa[i]);

            if(!vis[pos1]) vis[pos1] = true, cnt ++;
            if(!vis[pos2]) vis[pos2] = true, cnt ++;

        }
        else
        {
            memset(vis, false, sizeof vis);
            if(cnt * 2 > m) pos[cur ++] = sa[i - 1] - 1;
            cnt = 0;
        }
    }
    if(cnt * 2 >= m) pos[cur ++] = sa[n] - 1;
    return cur;
}

int main()
{
    bool flag = false;
    while(scanf("%d", &m) != EOF && m)
    {
        n = 0;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%s", a);
            for(int j = 0; a[j]; j ++) s[n ++] = a[j];
            len[i] = n;
            s[n ++] = 256 + i;
        }
        if(m == 1) {puts(a); continue; }
        s[-- n] = 0;
        build_sa(n + 1, 360);
        getHeight();
        int l = 0, r = 1000, res = 0;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(check(mid)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        if(flag) puts(""); flag = true;
        if(res)
        {
            check(res);
            for(int i = 0; i < cur; i ++)
            {
                for(int j = pos[i]; j < res + pos[i]; j ++) printf("%c", s[j]);
                puts("");
            }
        }
        else puts("?");
    }
    return 0;
}
