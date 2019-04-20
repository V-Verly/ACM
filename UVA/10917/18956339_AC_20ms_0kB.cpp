#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;

int mp[maxn][maxn], mp2[maxn][maxn];
int dis[maxn], n;

struct node
{
    int u, dis;
    bool operator <(const node & n) const {
        return dis > n.dis;
    }
};

void dijkstra()
{
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[2] = 0;
    priority_queue<node> que;
    que.push({2,0});
    while(!que.empty())
    {
        node f = que.top(); que.pop();
        int u = f.u, d = f.dis;
        if(d != dis[u]) continue;
        for(int v = 1; v <= n; v++) if(mp[u][v] && dis[u] + mp[u][v] < dis[v])
        {
            dis[v] = dis[u] + mp[u][v];
            que.push({v,dis[v]});
        }
    }
}

int dp[maxn];

int dfs(int u)
{
    if(u == 2) return 1;
    if(~dp[u]) return dp[u];
    int ans = 0;
    for(int v = 1; v <= n; v++) if(mp2[u][v]) ans += dfs(v);
    return dp[u] = ans;
}

int main()
{
    int m, u, v, w;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &m);
        memset(mp, 0, sizeof mp);
        memset(mp2, 0, sizeof mp2);
        memset(dp ,0xff, sizeof dp);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            mp[u][v] = mp[v][u] = w;
        }
        dijkstra();
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(mp[i][j] && dis[i] < dis[j]) mp2[j][i] = 1;
        printf("%d\n",dfs(1));
    }
    return 0;
}
