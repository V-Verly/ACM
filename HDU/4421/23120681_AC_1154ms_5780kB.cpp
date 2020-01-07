#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 500 + 10;
const int maxn = 1000 + 10;
int b[N][N];

struct TWO_SAT
{
	int n, m;
	int low[maxn], dfn[maxn], color[maxn], cnt, scc_cnt;
	bool instack[maxn];

	vector<int> g[maxn];
	stack<int> st;

	void init(int _n)
	{
		n = _n;
		cnt = scc_cnt = 0;
		memset(dfn, 0, sizeof dfn);
		memset(color, 0, sizeof color);
		for(int i = 0; i <= n * 2; i ++) g[i].clear();
	}

	void Tarjan(int u)
	{
		low[u] = dfn[u] = ++ cnt;
		st.push(u);
		instack[u] = true;
		for(const auto &v : g[u])
		{
			if(!dfn[v]) Tarjan(v), low[u] = min(low[u], low[v]);
			else if(instack[v]) low[u] = min(low[u], dfn[v]);
		}
		if(low[u] == dfn[u])
		{
			++ scc_cnt;
			int v;
			do{
				v = st.top(); st.pop();
				instack[v] = 0;
				color[v] = scc_cnt;
			} while(u != v);
		}
	}

	inline void add(int a, int b) { g[a].push_back(b); }

	inline void AND(int a, int b, int c)
	{
		if(c == 1) add(a, a + n), add(b, b + n);
		else add(a + n, b), add(b + n, a);
	}

	inline void OR(int a, int b, int c)
	{
		if(c == 0) add(a + n, a), add(b + n, b);
		else add(a, b + n), add(b, a + n);
	}

	inline void XOR(int a, int b, int c)
	{
		if(c == 0) add(a, b), add(a + n, b + n), add(b, a), add(b + n, a + n);
		else add(a, b + n), add(a + n, b ), add(b, a + n), add(b + n, a);
	}

	bool TWOSAT()
	{
		for(int i = 0; i < (n << 1); i ++) if(!dfn[i]) Tarjan(i);
		for(int i = 0; i < n; i ++) if(color[i] == color[i + n]) return false;
		return true;
	}
}solve;


int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				scanf("%d", &b[i][j]);
		bool res = 1;
		for(int i = 0; i < n; i ++) if(b[i][i] != 0) res = 0; 
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(b[i][j] != b[j][i]) res = 0;
		for(int k = 0; k < 31; k ++)
		{
			solve.init(n);
			for(int i = 0; i < n; i ++)
			{
				for(int j = i + 1; j < n; j ++)
				{
					if(i % 2 == 1 && j % 2 == 1) solve.OR(i, j, (b[i][j] >> k) & 1);
					else if(i % 2 == 0 && j % 2 == 0) solve.AND(i, j, (b[i][j] >> k) & 1);
					else solve.XOR(i, j, (b[i][j] >> k) & 1);
				}
			}
			res &= solve.TWOSAT();
		}
		printf("%s\n", res ? "YES" : "NO");
	}
	return 0;
}
