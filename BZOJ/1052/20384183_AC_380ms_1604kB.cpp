#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e4 + 10;
const int inf = 0x3f3f3f3f;

int n, x[maxn], y[maxn];
struct data{int x[maxn], y[maxn], tot; } tmp;

void cut(int lx, int rx, int ly, int ry)
{
    int tot = 0;
    for(int i = 0; i < tmp.tot; i ++)
        if(tmp.x[i] < lx || tmp.x[i] > rx || tmp.y[i] < ly || tmp.y[i] > ry)
            tmp.x[tot] = tmp.x[i], tmp.y[tot ++] = tmp.y[i];
    tmp.tot = tot;
}

void solve(int op, int len)
{
    int lx = inf, rx = -inf, ly = inf, ry = -inf;
    for(int i = 0; i < tmp.tot; i ++)
    {
        lx = min(lx, tmp.x[i]), rx = max(rx, tmp.x[i]);
        ly = min(ly, tmp.y[i]), ry = max(ry, tmp.y[i]);
    }
    if(op == 1) cut(lx, lx + len, ly, ly + len);
    else if(op == 2) cut(lx, lx + len, ry - len, ry);
    else if(op == 3) cut(rx - len, rx, ly, ly + len);
    else if(op == 4) cut(rx - len, rx, ry - len, ry);
}

bool check(int len)
{
    for(int a = 1; a <= 4; a ++)
    {
        for(int b = 1; b <= 4; b ++)
        {
            for(int i = 0; i < n; i ++)
                tmp.x[i] = x[i], tmp.y[i] = y[i];
            tmp.tot = n;
            solve(a, len), solve(b, len);
            int lx = inf, rx = -inf, ly = inf, ry = -inf;
            for(int i = 0; i < tmp.tot; i ++)
            {
                lx = min(lx, tmp.x[i]), rx = max(rx, tmp.x[i]);
                ly = min(ly, tmp.y[i]), ry = max(ry, tmp.y[i]);
            }
            if(rx - lx <= len && ry - ly <= len) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d%d", &x[i], &y[i]);
    int l = 0, r = 2e9, mid, ans;
    while(l <= r)
    {
        mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}
