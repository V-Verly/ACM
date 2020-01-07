#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;

vector<int> edge[maxn];
int indegree[maxn];

void add(int u, int v)
{
    edge[u].push_back(v);
    indegree[v]++;
}

char s[maxn];
int dp[maxn][26];

int Toposort(int n)
{
    queue<int> que;
    for (int i = 1; i <= n; i++)
        if (!indegree[i]) add(0, i);
    que.push(0);
    int cnt = 0, res = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        indegree[u] = -1;    //从图中删去此顶点
        cnt ++;
        for (int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i];
            indegree[v]--;    //删去图中以u为尾的弧
            for(int j = 0; j < 26; j ++) res = max(res, dp[v][j] = max(dp[v][j], dp[u][j] + (s[v] - 'a' == j)));
            if (!indegree[v]) que.push(v);    //将新增的当前入度为0的点压入队列中
        }
    }
    return (cnt < n + 1) ? -1 : res;
}

int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    while(m --)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    printf("%d\n", Toposort(n));
    return 0;
}
