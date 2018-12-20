/*************************************************************************
	> File Name: 1181.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月09日 星期五 21时47分24秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1000+10;

int n,path[10*maxn],cnt=0;
int G[maxn][maxn]={0};

void dfs(int u)
{
	for(int v=1;v<=n;v++)
	{
		if(G[u][v])
		{
			G[u][v]--;
			G[v][u]--;
			dfs(v);
		}
	}
	path[cnt++]=u;
}

int main()
{
	int m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		G[u][v]++;
		G[v][u]++;
	}
	dfs(1);
	for(int i=0;i<cnt;i++)
    	printf("%d%c",path[i],i==cnt-1?'\n':' ');
	return 0;
}