#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;

int head[maxn], cnt;
struct Edge {int nex, to, w; }edge[maxn<<1];

void add(int u, int v, int w)
{
    edge[cnt].nex = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}

int f[1<<10][maxn], ans[20];
bool in[maxn];

queue<int> que;

void spfa(int S)
{
    while(!que.empty())
    {
        int u = que.front(); que.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nex)
        {
            int v = edge[i].to;
            if(f[S][v] > f[S][u] + edge[i].w)
            {
                f[S][v] = f[S][u] + edge[i].w;
                if(!in[v]) que.push(v), in[v] = true;
            }
        }
    }
}

int Steiner_Tree(int n, int d)
{
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= d; i++)
        f[1 << (i - 1)][i] = f[1 << (d + i - 1)][n - i + 1] = 0;
    int lim = 1<<(d<<1);
    for(int S = 1; S < lim; S++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int s = (S - 1) & S; s; s = (s - 1) & S)
                f[S][i] = min(f[S][i], f[s][i] + f[S ^ s][i]);
            if(f[S][i] != inf) que.push(i), in[i] = true;
        }
        spfa(S);
    }
    lim = 1<<d;
    memset(ans, 0x3f, sizeof ans);
    for(int S = 1; S < lim; S++)
        for(int i = 1; i <= n; i++)
            ans[S] = min(ans[S], f[S^(S<<d)][i]);
    for(int S = 1; S < lim; S++)
        for(int s = (S - 1) & S; s; s = (s - 1) & S)
            ans[S] = min(ans[S], ans[s] + ans[S ^ s]);
    return ans[lim - 1] == inf ? -1 : ans[lim - 1];
}

int main()
{
    int n, m, d, u, v, w;
    scanf("%d%d%d", &n, &m, &d);
    memset(head, 0xff, sizeof head);
    while(m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    printf("%d\n", Steiner_Tree(n, d));
    return 0;
}
