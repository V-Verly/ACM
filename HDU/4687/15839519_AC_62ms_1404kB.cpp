#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=40+10;

int edge[maxn][maxn];
queue<int> que;

int n,pre[maxn],type[maxn],link[maxn],nex[maxn],vis[maxn];

void add(int u,int v)
{
	edge[u][v]=edge[v][u]=1;
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
		for(int i=1;i<=n;i++)
		{
		    if(!edge[x][i]) continue;
			int y=i;
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
	return ans/2;
}

void init()
{
    memset(edge,0,sizeof edge);
    memset(link,0,sizeof(link));
}

int main()
{
    int m,u[150],v[150];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            add(u[i],v[i]);
        }

        int cnt=maxmatch();
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            init();
            int x=u[i],y=v[i];
            for(int j=0;j<m;j++)
            {
                if(x==u[j]||x==v[j]||y==u[j]||y==v[j]) continue;
                edge[u[j]][v[j]]=edge[v[j]][u[j]]=1;
            }
            if(maxmatch()!=cnt-1) ans.push_back(i+1);
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
