#include <bits/stdc++.h>

using namespace std;

const int maxn = 250000 + 10;

struct SuffixAutomation
{
	int last, cnt;
	int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1], pos[maxn << 1];
    int sz[maxn << 1], a[maxn << 1], c[maxn << 1], f[maxn];

	void init()
	{
	    last = cnt = 1;
	    memset(ch[1], 0, sizeof ch[1]);
	    fa[1] = len[1] = 0;
    }

    int inline newnode(int idx)
    {
        ++cnt;
        memset(ch[cnt], 0, sizeof ch[cnt]);
        fa[cnt] = len[cnt] = 0;
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
		}
        sz[np] = 1;
	}

    void Toposort(int n)
    {
        long long ans = 0;
        for(int i = 1; i <= cnt; i ++) c[len[i]] ++;
        for(int i = 1; i <= cnt; i ++) c[i] += c[i - 1];
        for(int i = 1; i <= cnt; i ++) a[c[len[i]] --] = i;
        for(int i = cnt; i; i --) sz[fa[a[i]]] += sz[a[i]];
        for(int i = 1; i <= cnt; i ++) f[len[a[i]]] = max(f[len[a[i]]], sz[a[i]]);
        for(int i = n - 1; i; i --) f[i] = max(f[i], f[i + 1]);
        for(int i = 1; i <= n; i ++) printf("%d\n", f[i]);
    }
}sam;

char s[maxn];

int main()
{
    scanf("%s", s);
    sam.init();
    for(int i = 0; s[i]; i ++) sam.ins(s[i] - 'a');
    sam.Toposort(strlen(s));
    return 0;
}
