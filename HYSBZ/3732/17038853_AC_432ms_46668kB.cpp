/*************************************************************************
	> File Name: 3732.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月16日 星期五 18时36分57秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=3e5+10;

struct Edge
{
	int u,v,w;
	bool operator <(const Edge e) const {
		return w<e.w;
	}
}es[maxn];

int n,pre[maxn],val[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

vector<int> tree[maxn];

void add(int u,int v)
{
	tree[u].push_back(v);
	pre[v]=u;
}

int dep[maxn],fa[maxn][30];

void dfs(int u,int pre)	//预处理各节点深度+初始fa[u][0]
{
	dep[u]=dep[pre]+1;
	fa[u][0]=pre;
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v!=pre) dfs(v,u);
	}
}

void init()	//预处理fa数组
{
	for(int i=1;(1<<i)<=n;i++)
		for(int u=1;u<=n;u++)
			fa[u][i]=fa[fa[u][i-1]][i-1];
}

/**************求LCA(u,v)**************/

int LCA(int u,int v)
{

	if(dep[u]<dep[v])
		swap(u,v);

	int d=dep[u]-dep[v];
	for(int i=0;(1<<i)<=d;i++)	//将u上调d个距离
		if((1<<i)&d) u=fa[u][i];

	if(u==v) return u;	//特判此时u,v是否在同一位置，如果是，u,v都在LCA上

	for(int i=(int)log(n);i>=0;i--)	//同时上调u,v
	{
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];	//最后会使u,v成为LCA的子节点
}

int main()
{
	int m,k,u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=2*n;i++) pre[i]=i;
	for(int i=0;i<m;i++)
		scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
	sort(es,es+m);
	int index=n,lim=n<<1;
	for(int i=0;i<m;i++)
	{
		u=es[i].u,v=es[i].v,w=es[i].w;
		int fx=Find(u),fy=Find(v);
		if(fx==fy) continue;
		index++;
		add(index,fx);
		add(index,fy);
		val[index]=w;
		if(index==lim-1) break;
	}
	dep[0]=0;
	n=index;
	dfs(index,0);
	init();
	while(k--)
	{
		scanf("%d%d",&u,&v);
		printf("%d\n",val[LCA(u,v)]);
	}
	return 0;
}