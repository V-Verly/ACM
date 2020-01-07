#include <bits/stdc++.h>

using namespace std;

int n, k, a[50], vis[50];

bool dfs(int pos, int pre, int low, int high)
{
    if(pos == n)
    {
        k --;
        if(!k)
        {
            for(int i = 0; i < n; i ++) printf("%d%c", a[i]- low + 1, i == n - 1 ? '\n' : ' ');
            return true;
        }
        return false;
    }
    for(int i = - n + 1; i <= n - 1; i ++)
    {
        if(vis[i + pre]) continue;
        if(max(i + pre, high) - min(i + pre, low) >= n) continue;
        vis[i + pre] = true;
        a[pos] = i + pre;
        if(dfs(pos + 1, i + pre, min(i + pre, low), max(i + pre, high)))
        {
            vis[i + pre] = 0;
            return true;
        }
        vis[i + pre] = 0;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &k);
        vis[n] = 1;
        a[0] = n;
        dfs(1, n, n, n);
        vis[n] = 0;
    }
    return 0;
}
