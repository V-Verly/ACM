#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct Edge{ int from, to, cap, flow,cost; };

struct
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    int dis[maxn], path[maxn], a[maxn];

    void init(int n)
    {
        this->n = n;
        for(int i = 0; i <= n; i ++) G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool Bellman_Ford(int s, int t, int &flow, int &cost)
    {
        for(int i = 0; i <= n; i ++) dis[i] = inf;
        memset(inq, 0, sizeof inq);
        dis[s] = 0, inq[s] = true, path[s] = 0, a[s] = inf;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for(int i = 0; i < G[u].size(); i ++)
            {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && dis[e.to] > dis[u] + e.cost)
                {
                    dis[e.to] = dis[u] + e.cost;
                    path[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if(dis[t] == inf) return false;
        flow += a[t];
        cost += dis[t] * a[t];
        for(int u = t; u != s; u = edges[path[u]].from)
        {
            edges[path[u]].flow += a[t];
            edges[path[u] ^ 1].flow -= a[t];
        }
        return true;
    }

    int mincostMaxFlow(int s, int t)
    {
        int cost = 0, flow = 0;
        while(Bellman_Ford(s, t, flow, cost));
        return cost;
    }
}ans;

int LR[maxn], LC[maxn];
int mp[510][2];

vector<int> posR, posC;

int main()
{
    int n, m, pos, k;
    char op[5];
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d%d", &mp[i][0], &mp[i][1]);
        posR.push_back(mp[i][0]);
        posC.push_back(mp[i][1]);
    }
    posR.push_back(0);
    posC.push_back(0);
    sort(posR.begin(), posR.end());
    sort(posC.begin(), posC.end());
    posR.erase(unique(posR.begin(), posR.end()), posR.end());
    posC.erase(unique(posC.begin(), posC.end()), posC.end());
    memset(LR, 0x3f, sizeof LR);
    memset(LC, 0x3f, sizeof LC);
    scanf("%d", &m);
    for(int i = 0; i < m; i ++)
    {
        scanf("%s%d%d", op, &pos, &k);
        if(op[0] == 'R')
        {
            pos = lower_bound(posR.begin(), posR.end(), pos) - posR.begin();
            LR[pos] = min(LR[pos], k);
        }
        else if(op[0] == 'C')
        {
            pos = lower_bound(posC.begin(), posC.end(), pos) - posC.begin();
            LC[pos] = min(LC[pos], k);
        }
    }
    int S = 0, T = posR.size();
    ans.init(posR.size() + posC.size());
    for(int i = 1; i < posR.size(); i ++) ans.addEdge(i - 1, i, LR[i], 0);
    for(int i = 1; i < posC.size(); i ++) ans.addEdge(i + posR.size(), i + posR.size() - 1, LC[i], 0);
    for(int i = 0; i < n; i ++)
    {
        int x = lower_bound(posR.begin(), posR.end(), mp[i][0]) - posR.begin(),
            y = lower_bound(posC.begin(), posC.end(), mp[i][1]) - posC.begin() + posR.size();
        ans.addEdge(x, y, 1, - i - 1);
    }
    printf("%d\n", -ans.mincostMaxFlow(S, T));
    return 0;
}
