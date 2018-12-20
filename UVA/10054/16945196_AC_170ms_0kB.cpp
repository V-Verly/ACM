/*************************************************************************
	> File Name: 10054.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月10日 星期六 13时36分19秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int n=50;
int G[55][55];

void dfs(int u)
{
	for(int v=1;v<=n;v++)
	{
		if(G[u][v]) {
			G[u][v]--;
			G[v][u]--;
			dfs(v);
			printf("%d %d\n",v,u);
		}
	}
}

int main()
{
	int t,m,u,v;
	int degree[55];
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&m);
		memset(G,0,sizeof G);
		memset(degree,0,sizeof degree);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			G[u][v]++;
			G[v][u]++;
			degree[u]++;
			degree[v]++;
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(degree[i]%2) flag=false;
		printf("Case #%d\n",_);
		if(!flag) printf("some beads may be lost\n");
		else for(int i=1;i<=n;i++) dfs(i);
		if(_<t) printf("\n");
	}
	return 0;
}