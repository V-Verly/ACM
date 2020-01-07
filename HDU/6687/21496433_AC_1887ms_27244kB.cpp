#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int A[maxn], B[maxn];

struct Trie
{
    int tree[maxn * 70][2], tot;
    int sz[maxn * 70];

    inline int newnode()
    {
        tree[++ tot][0] = tree[tot][1] = 0;
        sz[tot] = 0;
        return tot;
    }

    void init()
    {
        tot = 0;
        newnode();
    }

    void ins(int x)
    {
        int root = 1; sz[root] ++;
        for(int i = 29; i >= 0; i --)
        {
            int id = (x >> i) & 1;
            if(!tree[root][id]) tree[root][id] = newnode();
            root = tree[root][id];
            sz[root] ++;
        }
    }
}a, b;

ll getans(int posA, int posB, int dep, int val)
{
    if(a.sz[posA] == 0 || b.sz[posB] == 0) return 0;
    if(dep == -1)
    {
        int num = min(a.sz[posA], b.sz[posB]);
        a.sz[posA] -= num, b.sz[posB] -= num;
        return 1ll * num * val;
    }
    ll res = getans(a.tree[posA][0], b.tree[posB][1], dep - 1, val + (1 << dep)) + getans(a.tree[posA][1], b.tree[posB][0], dep - 1, val + (1 << dep));
    res += getans(a.tree[posA][0], b.tree[posB][0], dep - 1, val) + getans(a.tree[posA][1], b.tree[posB][1], dep - 1, val);
    a.sz[posA] = a.sz[a.tree[posA][0]] + a.sz[a.tree[posA][1]];
    b.sz[posB] = b.sz[b.tree[posB][0]] + b.sz[b.tree[posB][1]];
    return res;
}

int main()
{
    int _, n;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &A[i]);
        for(int i = 1; i <= n; i ++) scanf("%d", &B[i]);
        a.init(), b.init();
        for(int i = 1; i <= n; i ++) a.ins(A[i]);
        for(int i = 1; i <= n; i ++) b.ins(B[i]);
        printf("%lld\n", getans(1, 1, 29, 0));
    }
    return 0;
}