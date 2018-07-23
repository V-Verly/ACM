#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn=1000+10;

vector<int> tree[maxn];
vector<int> query[maxn];

int pre[maxn],ans[maxn];
bool fa[maxn],vis[maxn];

int Find(int x)
{
	return x==pre[x]?x:Find(pre[x]);
}

void Union(int u,int v)
{
	int a=Find(u),b=Find(v);
	if(a!=b)
		pre[b]=a;
}

void Tarjan(int u)
{
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		Tarjan(v);
		Union(u,v);
		vis[v]=true;
	}
	for(int i=0;i<query[u].size();i++)
	{
		int e=query[u][i];
		if(vis[e])
            ans[Find(e)]++;
	}
}

int main()
{
	int N,q,u,v,t,root;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=1;i<=N;i++)
		{
			fa[i]=vis[i]=false;
			ans[i]=0,pre[i]=i;
			tree[i].clear();
			query[i].clear();
		}
		for(int i=1;i<=N;i++)
		{
			scanf("%d:(%d)",&u,&t);
            while(t--)
            {
                scanf("%d",&v);
                tree[u].push_back(v);
                fa[v]=true;
            }
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf(" (%d%d)",&u,&v);
            query[u].push_back(v);
            query[v].push_back(u);
        }
        for(int i=1;i<=N;i++)
        	if(!fa[i]) root=i;
        Tarjan(root);
        for(int i=1;i<=N;i++)
        	if(ans[i]) printf("%d:%d\n",i,ans[i]);
	}
	return 0;
}
