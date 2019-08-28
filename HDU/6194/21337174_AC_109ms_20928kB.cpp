#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct SuffixAutomation
{
    int last, cnt;
    int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1], pos[maxn << 1];
    int sz[maxn << 1], a[maxn << 1], c[maxn << 1];

    void init()
    {
        last = cnt = 1;
        memset(ch[1], 0, sizeof ch[1]);
        fa[1] = len[1] = sz[1] = 0;
    }

    int inline newnode(int idx)
    {
        ++cnt;
        memset(ch[cnt], 0, sizeof ch[cnt]);
        fa[cnt] = len[cnt] = sz[cnt] = 0;
        pos[cnt] = idx;
        return cnt;
    }

    void ins(int c)
    {
        int p = last , np = newnode(pos[last] + 1);
        last = np, len[np] = len[p] + 1;
        for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if(!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if(len[p] + 1 == len[q]) fa[np] = q;
            else
            {
                int nq = newnode(pos[p] + 1);
                len[nq] = len[p] + 1;
                memcpy(ch[nq], ch[q], sizeof ch[q]);
                fa[nq] = fa[q], fa[q] = fa[np] = nq;
                for(; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        };
        sz[np] = 1;
    }

    void cal(int k)
    {
        long long ans = 0;
        memset(a, 0, sizeof (int) * (cnt + 1));
        memset(c, 0, sizeof (int) * (cnt + 1));
        for(int i = 1; i <= cnt; i ++) c[len[i]] ++;
        for(int i = 1; i <= cnt; i ++) c[i] += c[i - 1];
        for(int i = 1; i <= cnt; i ++) a[c[len[i]] --] = i;
        for(int i = cnt; i; i --) sz[fa[a[i]]] += sz[a[i]];
        for(int i = 1; i <= cnt; i ++) if(sz[a[i]] == k) ans += len[a[i]] - len[fa[a[i]]];
        printf("%lld\n", ans);
    }
}sam;

char s[maxn];

int main()
{
    int _, k;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d%s", &k, s);
        sam.init();
        for(int i = 0; s[i]; i ++) sam.ins(s[i] - 'a');
        sam.cal(k);
    }
    return 0;
}