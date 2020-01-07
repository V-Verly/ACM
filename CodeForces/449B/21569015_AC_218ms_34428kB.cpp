#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int head[maxn], dis[maxn], cnt, n;

struct Edge { int nex,to,w, col; } edge[20*maxn];

void add(int u,int v,int w, int col)
{
    edge[++cnt].nex=head[u];
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].col = col;
    head[u]=cnt;
}

int link[maxn], mark[maxn];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    memset(dis, 0x3f, sizeof dis);
    memset(link, 0xff, sizeof link);
    que.push({0, s}); dis[s] = 0;
    while(!que.empty())
    {
        auto f = que.top(); que.pop();
        int u = f.second, d = f.first;
        if(d != dis[u]) continue;
        for(int i = head[u]; ~i; i = edge[i].nex)
        {
            int v = edge[i].to, w = edge[i].w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                link[v] = edge[i].col;
                que.push({dis[v], v});
            }
            else if(dis[u] + w == dis[v] && edge[i].col == 0) link[v] = edge[i].col;
        }
    }
}

int main()
{
    int m, k, u, v, w;
    scanf("%d%d%d", &n, &m, &k);
    memset(head, 0xff, sizeof head);
    while(m --)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w, 0);
        add(v, u, w, 0);
    }
    for(int i = 1; i <= k; i ++)
    {
        scanf("%d%d", &v, &w);
        mark[v] ++;
        add(1, v, w, 1);
        add(v, 1, w, 1);
    }
    dijkstra(1);
    int res = 0;
    for(int i = 2; i <= n; i ++) if(mark[i])
    {
        if(link[i] == 0) res += mark[i];
        else res += mark[i] - 1;
    }
    printf("%d\n", res);
    return 0;
}
