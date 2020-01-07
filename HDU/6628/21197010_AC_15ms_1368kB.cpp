#include <bits/stdc++.h>

using namespace std;

int n, k;
int d[50], vis[50];

bool dfs(int id, int low, int high)
{
    if(id == n)
    {
        k --;
        if(!k)
        {
            for(int i = 0; i < n; i ++) printf("%d%c", d[i] - low + 1, i == n - 1 ? '\n' : ' ');
            return true;
        }
        return false;
    }
    for(int i = high - (n - 1); i <= low + (n - 1); i ++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        d[id] = i;
        if(dfs(id + 1, min(low, i), max(high, i)))
        {
            vis[i] = 0;
            return true;
        }
        vis[i] = 0;
    }
    return false;
}

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d%d", &n, &k);
        d[0] = n;
        vis[n] = 1;
        dfs(1, n, n);
        vis[n] = 0;
    }
    return 0;
}
