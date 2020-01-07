#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 10;

struct SuffixAutomation
{
	int last, cnt;
	int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1], pos[maxn << 1];
    int sz[maxn << 1], a[maxn << 1], c[maxn << 1];

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

    long long solve()
    {
        //求本质不同的子串个数
        long long ans = 0;
        for(int i = 1; i <= cnt; i ++) ans += len[i] - len[fa[i]];
        return ans;
    }
}sam;

char s[maxn];

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%s", s + 1);
        int q, l, r;
        scanf("%d", &q);
        while(q --)
        {
            scanf("%d%d", &l, &r);
            sam.init();
            for(int i = l; i <= r; i ++) sam.ins(s[i] - 'a');
            printf("%lld\n", sam.solve());
        }
    }
    return 0;
}
