#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
char s[1000000 + 10], t[500 + 10];

class AC_automation
{
public:
    int trie[maxn][26], cnt;
    int tag[maxn], mp[maxn], ans[maxn];
    int fail[maxn];

    void init()
    {
        memset(trie, 0, sizeof trie);
        memset(tag, 0, sizeof tag);
        memset(fail, 0, sizeof fail);
        memset(ans, 0, sizeof ans);
        cnt = 0;
    }

    void insert(char *str, int id)
    {
        int root = 0;
        for (int i = 0; str[i]; i++)
        {
            int id = str[i] - 'a';
            if (!trie[root][id]) trie[root][id] = ++cnt;
            root = trie[root][id];
        }
        if(!tag[root]) tag[root] = id;
        mp[id] = tag[root];
    }

    void build()
    {
        queue<int> que;
        for (int i = 0; i < 26; i++) if (trie[0][i]) que.push(trie[0][i]);
        while (!que.empty())
        {
            int k = que.front();
            // tag[k] += tag[fail[k]];
            que.pop();
            for (int i = 0; i < 26; i++)
            {
                if (trie[k][i])
                {
                    fail[trie[k][i]] = trie[fail[k]][i];
                    que.push(trie[k][i]);
                } else trie[k][i] = trie[fail[k]][i];
            }
        }
    }

    void query(char *str, int n)
    {
        int p = 0, res = 0;
        for (int i = 0; str[i]; i++)
        {
            p = trie[p][str[i] - 'a'];
            for (int j = p; j && ~tag[j]; j = fail[j]) if(tag[j]) ans[tag[j]] ++;
        }
        for(int i = 1; i <= n; i ++) printf("%d\n", ans[mp[i]]);
    }
} AC;

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _ ++)
    {
        AC.init();
        scanf("%d", &n);
        scanf("%s", s);
        printf("Case %d:\n", _);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%s", t);
            AC.insert(t, i);
        }
        AC.build();
        AC.query(s, n);
    }
    return 0;
}
