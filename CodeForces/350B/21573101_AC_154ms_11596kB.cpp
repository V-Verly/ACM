#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

vector<int> edge[maxn];
int indegree[maxn], a[maxn];

void add(int u, int v)
{
    edge[u].push_back(v);
    indegree[v]++;
}

int dp[maxn], path[maxn], res, p;

void dfs(int u, int k)
{
    if(edge[u].size() == 0)
    {
        if(k + 1 > res)
        {
            res = k + 1;
            p = u;
        }
        return;
    }
    for(auto v : edge[u])
    {
        if(indegree[v] > 1 || a[v])
        {
            if(k + 1 > res)
            {
                res = k + 1;
                p = u;
            }
            continue;
        }
        path[v] = u;
        dfs(v, k + 1);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1, x; i <= n; i ++)
    {
        scanf("%d", &x);
        if(x) add(i, x);
    }
    for(int i = 1; i <= n; i ++) if(a[i]) dfs(i, 0);
    vector<int> ans;
    for(; p; p = path[p]) ans.push_back(p);
    printf("%d\n", ans.size());
    for(auto v : ans) printf("%d ", v);
    return 0;
}
