#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
char s[maxn];
ll p, q, dp[maxn];

struct SuffixAutomation
{
	int last, cnt;
	int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1];

	void init()
	{
	    last = cnt = 1;
	    memset(ch[1], 0, sizeof ch[1]);
	    fa[1] = len[1] = 0;
    }

    int inline newnode()
    {
        ++cnt;
        memset(ch[cnt], 0, sizeof ch[cnt]);
        fa[cnt] = len[cnt] = 0;
        return cnt;
    }

	void ins(int c)
	{
		int p = last , np = newnode();
		last = np, len[np] = len[p] + 1;
		for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
		if(!p) fa[np] = 1;
		else
		{
			int q = ch[p][c];
			if(len[p] + 1 == len[q]) fa[np] = q;
			else
			{
				int nq = newnode();
				len[nq] = len[p] + 1;
				memcpy(ch[nq], ch[q], sizeof ch[q]);
				fa[nq] = fa[q], fa[q] = fa[np] = nq;
				for(; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
			}
		}
	}

	ll solve()
	{
	    int n = strlen(s);
	    init();
	    ins(s[0] - 'a');
	    dp[0] = p;
	    int pos = 1, j = 0;
	    for(int i = 1; i < n; i ++)
        {
            dp[i] = dp[i - 1] + p;
            for(;;)
            {
                while(pos != 1 && len[fa[pos]] >= i - j - 1) pos = fa[pos];
                if(ch[pos][s[i] - 'a'])
                {
                    pos = ch[pos][s[i] - 'a'];
                    break;
                }
                else ins(s[++ j] - 'a');
            }
            dp[i] = min(dp[i], dp[j] + q);
        }
        return dp[n - 1];
	}
}sam;


int main()
{
    while(scanf("%s", s) != EOF)
    {
        scanf("%lld%lld", &p, &q);
        printf("%lld\n", sam.solve());
    }
    return 0;
}
