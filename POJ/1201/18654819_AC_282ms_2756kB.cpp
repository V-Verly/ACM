#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=50000+10;
const int inf=0x3f3f3f3f;

struct Edge {int nex,to,w; } edge[10*maxn];

int head[maxn],cnt,dis[maxn],s,t;
bool vis[maxn];

void init()
{
	cnt=0;
	memset(head,0xff,sizeof head);
}

void add(int u,int v,int w)
{
	edge[cnt].nex=head[u];
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt++;
}

void spfa(int u)
{
	int v,w;
	for(int i=s;i<=t;i++) dis[i]=-inf,vis[i]=false;
	dis[u]=0;
	queue<int> que;
	que.push(u);
	vis[u]=true;
	while(!que.empty())
	{
		u=que.front();
		que.pop();
		vis[u]=false;
		for(int i=head[u];~i;i=edge[i].nex)
		{
			v=edge[i].to,w=edge[i].w;
			if(dis[u]+w>dis[v])
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					que.push(v);
					vis[v]=true;
				}
			}
		}
	}
}

int main()
{
    int m,a,b,c;
    while(scanf("%d",&m)!=EOF)
    {
        s=inf,t=-inf;
        init();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b+1,c);
            s=min(s,a);
            t=max(t,b+1);
        }
        for(int i=s;i<=t;i++)
        {
            add(i,i+1,0);
            add(i+1,i,-1);
        }
        spfa(s);
        printf("%d\n",dis[t]);
    }
    return 0;
}
