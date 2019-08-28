#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int pre[maxn];
bool vis[maxn];

struct edge{ int u, v, c; }es[maxn];

int Find(int x) { return x == pre[x] ? x : pre[x] = Find(pre[x]); }

bool Merge(int u, int v)
{
    int fx = Find(u), fy = Find(v);
    if(fx == fy) return false;
    pre[fx] = fy;
    return true;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i ++) scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].c);
    for(int i = 1; i <= n; i ++) pre[i] = i;
    for(int i = 0; i < m; i ++) if(es[i].c == 1) Merge(es[i].u, es[i].v);
    for(int i = 0; i < m; i ++) if(es[i].c == 0 && Merge(es[i].u, es[i].v))  vis[i] = true;
    for(int i = 1; i <= n; i ++) pre[i] = i;
    int cnt = 0;
    for(int i = 0; i < m; i ++) if(vis[i] && Merge(es[i].u, es[i].v)) cnt ++;
    for(int i = 0; i < m; i ++) if(cnt < k && es[i].c == 0 && Merge(es[i].u, es[i].v)) vis[i] = true, cnt ++;
    if(cnt != k) return 0 * printf("no solution\n");
    for(int i = 0; i < m; i ++) if(es[i].c == 1 && Merge(es[i].u, es[i].v)) vis[i] = true;
    for(int i = 0; i < m; i ++) if(vis[i]) printf("%d %d %d\n", es[i].u, es[i].v, es[i].c);
    return 0;
}
