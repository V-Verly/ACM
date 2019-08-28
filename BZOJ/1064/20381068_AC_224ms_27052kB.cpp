#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct Edge {int nex, to, w; }edge[20 * maxn];
int head[maxn], cnt = 1;
bool vis[maxn];
int dis[maxn], ans, ans1;

void add(int u, int v, int w)
{
    edge[cnt].nex = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt ++;
}

void dfs(int u)
{
    vis[u] = true;
    for(int i = head[u]; i; i = edge[i].nex)
    {
        int v = edge[i].to, w = edge[i].w;
        if(vis[v]) ans = __gcd(ans, abs(dis[u] + w - dis[v]));
        else dis[v] = dis[u] + w, dfs(v);
    }
}

int bfs(int s)
{
    queue<int> que;
    que.push(s);
    vis[s] = true, dis[s] = 0;
    int u, v, w, x = 0, y = 0;
    while(!que.empty())
    {
        u = que.front(); que.pop();
        for(int i = head[u]; i; i = edge[i].nex)
        {
            v = edge[i].to, w = edge[i].w;
            if(vis[v]) continue;
            dis[v] = dis[u] + w;
            x = max(x, dis[v]), y = min(y, dis[v]);
            vis[v] = true;
            que.push(v);
        }
    }
    return x - y + 1;
}

int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    while(m --)
    {
        scanf("%d%d", &u, &v);
        add(u, v, 1);
        add(v, u, -1);
    }
    for(int i = 1; i <= n; i ++) if(!vis[i]) dfs(i);
    if(ans)
    {
        if(ans < 3) return 0 * printf("-1 -1\n");
        for(int i = 3; i <= ans; i ++) if(ans % i == 0)
            return 0 * printf("%d %d\n", ans, i);
    }
    else
    {
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        for(int i = 1; i <= n; i ++) if(!vis[i]) ans += bfs(i);
        if(ans < 3) printf("-1 -1\n");
        else printf("%d 3\n", ans);
    }
    return 0;
}
