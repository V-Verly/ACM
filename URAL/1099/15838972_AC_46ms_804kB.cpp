#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=1000+10;

vector<int> edge[maxn];
queue<int> que;

int n,pre[maxn],type[maxn],link[maxn],nex[maxn],vis[maxn];

void add(int u,int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
}

int Find(int x){return x==pre[x]?x:pre[x]=Find(pre[x]); }

void combine(int x,int lca)	//如果找到奇环，对当前点x和找到的
{
	while(x!=lca)
	{
		int u=link[x],v=nex[u];
		if(Find(v)!=lca) nex[v]=u;
		if(type[u]==1) type[u]=2,que.push(u);
		pre[Find(x)]=Find(u);
		pre[Find(u)]=Find(v);
		x=v;
	}
}

void contrack(int x,int y)
{
	int lca=x;
	memset(vis,0,sizeof(vis));
	for(int i=x;i;i=nex[link[i]])
	{
		i=Find(i);
		vis[i]=1;
	}
	for(int i=y;i;i=nex[link[i]])
	{
		i=Find(i);
		if(vis[i])
		{
			lca=i;
			break;
		}
	}
	if(lca!=Find(x)) nex[x]=y;
	if(lca!=Find(y)) nex[y]=x;
	combine(x,lca);
	combine(y,lca);
}

void bfs(int s)
{
	memset(type,0,sizeof(type));
	memset(nex,0,sizeof(nex));
	for(int i=1;i<=n;i++) pre[i]=i;
	while(!que.empty()) que.pop();
	que.push(s);type[s]=2;
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		for(int i=0;i<edge[x].size();i++)
		{
			int y=edge[x][i];
			if(Find(x)==Find(y)||link[x]==y||type[y]==1) continue;
			if(type[y]==2) contrack(x,y);
			else if(link[y])
			{
				nex[y]=x;
				type[y]=1;
				type[link[y]]=2;
				que.push(link[y]);
			}
			else
			{
				nex[y]=x;
				int pos=y,u=nex[pos],v=link[u];
				while(pos)
				{
					link[pos]=u;link[u]=pos;
					pos=v;
					u=nex[pos];v=link[u];
				}
				return;
			}
		}
	}
}

int maxmatch()
{
	for(int i=1;i<=n;i++) if(!link[i]) bfs(i);
	int ans=0;
	for(int i=1;i<=n;i++) if(link[i]) ans++;
	return ans;
}

void init()
{
    for(int i=1;i<=n;i++) edge[i].clear();
    memset(link,0,sizeof(link));
}

int main()
{
    int u,v;
    init();
    scanf("%d",&n);
    while(scanf("%d%d",&u,&v)!=EOF) add(u,v);
    printf("%d\n",maxmatch());
    for(int i=1;i<=n;i++) if(link[i]&&link[i]>i) printf("%d %d\n",i,link[i]);
    return 0;
}
