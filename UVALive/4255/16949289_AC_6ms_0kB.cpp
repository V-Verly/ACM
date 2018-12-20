/*************************************************************************
	> File Name: 4255.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月10日 星期六 15时43分22秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[15];
int degree[15],ans[15];

void add(int u,int v)
{
	edge[u].push_back(v);
	degree[v]++;
}

void Toposort(int n)
{
	queue<int> que;
	int low=-10;
	for(int i=0;i<=n;i++)
		if(!degree[i]) que.push(i),ans[i]=low;
	low++;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		degree[u]--;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			degree[v]--;
			if(!degree[v]) que.push(v),ans[v]=low;
		}
		low++;
	}
}

int main()
{
	int T,n,b[15];
	char s[60];
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) edge[i].clear();
		memset(degree,0,sizeof degree);
		scanf("%s",s);
		int p=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(s[p]=='-') add(j,i-1);
				else if(s[p]=='+') add(i-1,j);
				p++;
			}
		}
		Toposort(n);
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i]-ans[i-1],i==n?'\n':' ');
	}
	return 0;
}