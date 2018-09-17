#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e4+10;

int head[maxn],tot,longest[maxn],secondary[maxn],top[maxn],mark[maxn];

struct node
{
	int to,nex,v;
	node(){}
	node(int a,int b,int c):to(a),nex(b),v(c){}
}edge[2*maxn];

void add(int u,int v,int w)
{
	edge[tot]=node(v,head[u],w);
	head[u]=tot++;
	edge[tot]=node(u,head[v],w);
	head[v]=tot++;
}

void dfs(int u,int fa)
{
	longest[u]=secondary[u]=0;
	mark[u]=-1;
	for(int k=head[u];k!=-1;k=edge[k].nex)
	{
		int v=edge[k].to;
		if(v==fa) continue;
		dfs(v,u);
		if(longest[u]<=longest[v]+edge[k].v)
		{
			secondary[u]=longest[u];
			longest[u]=longest[v]+edge[k].v;
			mark[u]=v;
		}
		if(secondary[u]<=longest[v]+edge[k].v&&mark[u]!=v)
			secondary[u]=longest[v]+edge[k].v;
	}
}

void dfs1(int u,int fa)
{
	for(int k=head[u];k!=-1;k=edge[k].nex)
	{
		int v=edge[k].to;
		if(v==fa) continue;
		if(mark[u]!=v)
			top[v]=max(longest[u],top[u])+edge[k].v;
		else
			top[v]=max(secondary[u],top[u])+edge[k].v;
		dfs1(v,u);
	}
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int v,w;
		tot=0;
		memset(head,-1,sizeof(head));
		for(int u=2;u<=N;u++)
		{
			scanf("%d%d",&v,&w);
			add(u,v,w);
		}
		dfs(1,0);
		memset(top,0,sizeof(top));
		dfs1(1,0);
		top[1]=secondary[1];
		for(int i=1;i<=N;i++)
			printf("%d\n",max(top[i],longest[i]));
	}
	return 0;
}
