/*************************************************************************
	> File Name: 1182.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月09日 星期五 23时31分17秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1<<14;

vector<int> G[maxn];
int vis[maxn][maxn]={0};
int path[maxn],cnt=0,m;

void dfs(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!vis[u][v]) {
			vis[u][v]=1;
			dfs(v);
		}
	}
	path[cnt++]=u;
}

int main()
{
	int n,u,v,x;
	scanf("%d",&n);
	m=1<<n-1;
	x=(1<<n-2)-1;
	for(int i=0;i<m;i++)
	{
		u=i&x;
		for(int j=0;j<m;j++)
		{
			v=j>>1;
			if(u==v) G[i].push_back(j);
		}
	}
	dfs(0);
	for(int i=cnt-1;i>0;i--)
		printf("%d",path[i]>>n-2);
	printf("\n");
	return 0;
}