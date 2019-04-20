#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 31 *(5e5 + 10);

int trie[maxn][2], tot;
int sz[maxn], ext[maxn];
int cnt[31][2];

ll ans;

void init()
{
    memset(trie, 0, sizeof trie);
    memset(sz, 0, sizeof sz);
    memset(ext, 0, sizeof ext);
    memset(cnt, 0, sizeof cnt);
    ans = tot = 0;
}

void insert_ch(int x)
{
    int root = 0;
    for(int i = 29; i >= 0; i--)
    {
        int id = (x >> i) & 1;
        if(!trie[root][id]) trie[root][id] = ++tot;
        cnt[i][id]++;
        if(trie[root][id ^ 1])
        {
            int now = trie[root][id ^ 1];
            ans += 1ll * sz[now] * (sz[now] - 1) / 2;
            ans += 1ll * (cnt[i][1 ^ id] - sz[now]) * sz[now] - ext[now];
        }
        root = trie[root][id];
        sz[root]++;
        ext[root] += cnt[i][id] - sz[root];
    }
}

int main()
{
    int t, n, x;
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            insert_ch(x);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
