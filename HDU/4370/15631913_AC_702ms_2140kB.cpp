#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=300+10;
const int inf=0x3f3f3f3f;
int n,edge[maxn][maxn],dis[maxn];
bool vis[maxn];

void SPFA(int s)
{
    queue<int> que;
	for(int i=1;i<=n;i++)
    {
        if(s==i)
        {
            dis[i]=inf;
            vis[i]=false;
        }
        else
        {
            dis[i]=edge[s][i];
            vis[i]=true;
            que.push(i);
        }
    }
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=false;
		for(int v=1;v<=n;v++)
		{
			if(u==v) continue;
			if(dis[v]>dis[u]+edge[u][v])
			{
				dis[v]=dis[u]+edge[u][v];
				if(vis[v]==false) que.push(v);
			}
		}
	}
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(edge,inf,sizeof edge);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&edge[i][j]);
        SPFA(n);int c=dis[n];SPFA(1);
        printf("%d\n",min(dis[n],c+dis[1]));
    }
    return 0;
}
