#include <bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;

struct Edge{int nex, to, w; } edge[maxn];
int head[maxn], cnt;
int L, R, dp[maxn];

void init()
{
    cnt = 0;
    memset(head, 0xff, sizeof head);
    memset(dp, 0xff, sizeof dp);
}

void add(int u, int v, int w)
{
    edge[cnt].nex = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}

void dfs(int u, int step, int dis)
{
    if(head[u] == -1)
    {
        if(L <= dis && dis <= R) dp[u] = 0;
        return;
    }
    int x=1e9+7,y=-1;
    bool flag = false;
    for(int i=head[u]; ~i; i=edge[i].nex)
    {
        dfs(edge[i].to, step + 1, dis + edge[i].w);
        if(dp[edge[i].to] == -1) continue;
        flag = true;
        if(step % 2) x = min(x, dp[edge[i].to] + edge[i].w);
        else y = max(y, dp[edge[i].to] + edge[i].w);
    }
    if(flag) dp[u] = step % 2 ?x : y;
}

int main()
{
    int n, u, v, w;
    while(~scanf("%d%d%d", &n, &L, &R))
    {
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }
        dfs(0, 0, 0);
        if(~dp[0]) printf("%d\n", dp[0]);
        else printf("Oh, my god!\n");
    }
    return 0;
}
