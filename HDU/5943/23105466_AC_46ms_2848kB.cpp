#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 600 + 10;

struct Hungary
{
	int n, edge[maxn][maxn], linker[maxn];
	bool vis[maxn];

	void init(int _n) { n = _n; memset(edge, 0, sizeof edge); } 

	bool path(int u)
	{
		for(int v = 1; v <= n; v ++)
		{
			if(edge[u][v] && !vis[v])
			{
				vis[v] = true;
				if(linker[v] == -1 || path(linker[v]))
				{
					linker[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int hungary()
	{
		int res = 0;
		memset(linker, 0xff, sizeof linker);
		for(int i = 1; i <= n; i ++)
		{
			memset(vis, false, sizeof vis);
			res += path(i);
		}
		return res;
	}
}solve;

int main()
{
	int T, n, s;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _ ++)
	{
		printf("Case #%d: ", _);
		scanf("%d%d", &n, &s);
		if(s < n) swap(s, n);
		if(n > 600) { puts("No"); continue; }
		solve.init(n);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if((j + s) % i == 0) solve.edge[i][j] = 1;
		printf("%s\n", solve.hungary() == n ? "Yes" : "No");
	}
	return 0;
}
