#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
char s[maxn][maxn];
int mp[maxn][maxn];
bool vis[maxn][maxn];
int ans[maxn * maxn], n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void BFS(int x, int y, int p)
{
    queue<pair<int, int> > que;
    que.push({x, y});
    vis[x][y] = true;
    while(!que.empty())
    {
        auto f = que.front(); que.pop();
        mp[f.first][f.second] = p;
        for(int i = 0; i < 4; i ++)
        {
            int fx = f.first + dx[i], fy = f.second + dy[i];
            if(check(fx, fy))
            {
                if(s[fx][fy] == '*') ans[p] ++;
                else if(!vis[fx][fy]) vis[fx][fy] = true, que.push({fx, fy});
            }
        }
    }
}

int main()
{
    int k, cnt = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(s[i][j] == '.' && !vis[i][j]) BFS(i, j, ++ cnt);
    while(k --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", ans[mp[x][y]]);
    }
    return 0;
}
