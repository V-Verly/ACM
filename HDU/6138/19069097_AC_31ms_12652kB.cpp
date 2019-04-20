#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

class AC_automation
{
public:
    int trie[maxn][26], cnt;
    int pos[maxn], len[maxn];
    int fail[maxn], pre[maxn];
    int vis[maxn];

    void init()
    {
        pre[0] = len[0] = 0;
        cnt = 0;
        memset(trie, 0, sizeof trie);
        memset(fail, 0, sizeof fail);
        memset(vis, 0, sizeof vis);
    }

    void insert(char *str, int id)
    {
        int root = 0;
        for(int i = 0; str[i]; i++)
        {
            int id = str[i] - 'a';
            if(!trie[root][id])
            {
                trie[root][id] = ++cnt;
                len[trie[root][id]] = len[root] + 1;
                pre[trie[root][id]] = root;
            }
            root = trie[root][id];
        }
        pos[id] = root;
    }

    void build()
    {
        queue<int> que;
        for(int i = 0; i < 26; i++) if(trie[0][i]) que.push(trie[0][i]);
        while(!que.empty())
        {
            int k = que.front(); que.pop();
            for(int i = 0; i < 26; i++)
            {
                if(trie[k][i]) {
                    fail[trie[k][i]] = trie[fail[k]][i];
                    que.push(trie[k][i]);
                }
                else trie[k][i] = trie[fail[k]][i];
            }
        }
    }

    int check(int x, int y,int cur)
    {
        memset(vis, 0, sizeof vis);
        for(int i = pos[x]; i; i = pre[i])
            for(int p = i; p&&vis[p] != cur; p = fail[p]) vis[p] = cur;
        int ans = 0;
        for(int i = pos[y]; i; i = pre[i])
            for(int p = i; p&&len[p] >= ans; p = fail[p]) if(vis[p]==cur) ans = max(ans, len[p]);
        return ans;
    }
}AC;

char s[maxn];

int main()
{
    int t, n, q, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        AC.init();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            AC.insert(s, i + 1);
        }
        AC.build();
        scanf("%d", &q);
        for(int i = 1; i <= q; i++)
        {
            scanf("%d%d",&x, &y);
            printf("%d\n",AC.check(x, y, q));
        }
    }
    return 0;
}
