/*************************************************************************
	> File Name: 1176.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月09日 星期五 21时03分20秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=10000+10;

int degree[maxn]={0},vis[maxn]={0},cnt=0;
vector<int> G[maxn];

void dfs(int x)
{
	cnt++;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	int n,m,u,v,ans=0;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		if(degree[i]%2) ans++;
	printf("%s\n",cnt==n&&(ans==0||ans==2)?"Full":"Part");
	return 0;
}