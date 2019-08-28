#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e4 + 10;

struct SuffixAutomation
{
	int last, cnt;
	int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1], pos[maxn << 1];

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
	}

	int solve(int n)
	{
	    int p = 1;
	    while(n --)
        {
            for(int i = 0; i < 26; i ++) if(ch[p][i])
            {
                p = ch[p][i];
                break;
            }
        }
        return pos[p];
	}
}sam;

char s[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%s", s);
        int n = strlen(s);
        sam.init();
        for(int i = 0; i < n; i ++) sam.ins(s[i] - 'a');
        for(int i = 0; i < n; i ++) sam.ins(s[i] - 'a');
        int k = sam.solve(n);
        printf("%d\n", k - n + 1);
    }
    return 0;
}
