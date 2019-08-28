#include <bits/stdc++.h>

using namespace std;

int a, b, c, m, n, mod;
int r[100][100];
int h[100], f[100][100][100];
bool vis[100];

int dp(int x)
{
    int cnt = 0, p;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= n; i ++) if(!vis[i])
    {
        vis[i] = true;
        h[++ cnt] = 1, p = i;
        while(!vis[r[x][p]])
        {
            h[cnt] ++;
            p = r[x][p];
            vis[p] = true;
        }
    }
    memset(f, 0, sizeof f);
    f[0][0][0] = 1;
    for(int p = 1; p <= cnt; p ++)
    {
        for(int i = a; i >= 0; i --)
        {
            for(int j = b; j >= 0; j --)
            {
                for(int k = c; k >= 0; k --)
                {
                    if(i >= h[p]) (f[i][j][k] += f[i - h[p]][j][k]) %= mod;
                    if(j >= h[p]) (f[i][j][k] += f[i][j - h[p]][k]) %= mod;
                    if(k >= h[p]) (f[i][j][k] += f[i][j][k - h[p]]) %= mod;
                }
            }
        }
    }
    return f[a][b][c];
}

int inv(int a, int n = mod - 2)
{
    int ans = 1, base = a;
    while(n)
    {
        if(n & 1) (ans *= base) %= mod;
        (base *= base) %= mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d%d%d", &a, &b, &c, &m, &mod);
    n = a + b + c;
    for(int i = 1; i <= n; i ++) r[0][i] = i;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            scanf("%d", &r[i][j]);
    int ans = 0;
    for(int i = 0; i <= m; i ++)
        (ans += dp(i)) %= mod;
    printf("%d\n", ans * inv(m + 1) % mod);
    return 0;
}
