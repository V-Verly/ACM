#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=200+10;
const int INF=0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edge{int to,cap,rev;};

struct Dinic
{
	vector<edge> G[MAX_V];	//图的邻接表表示
	int level[MAX_V];	//顶点到源点的距离标号
	int iter[MAX_V];	//当前弧

	void init(int n)
	{
	    for(int i=0;i<=n;i++) G[i].clear();
	}

	void add(int from,int to,int cap)
	{
		G[from].push_back((edge){to,cap,G[to].size()});
		G[to].push_back((edge){from,0,G[from].size()-1});
	}

	//计算从源点出发的距离标号
	void bfs(int s)
	{
		memset(level,-1,sizeof(level));
		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty())
		{
			int v=que.front();que.pop();
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0&&level[e.to]<0)
				{
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}

	//通过DFS寻找增广路
	int dfs(int v,int t,int f)
	{
		if(v==t) return f;
		for(int &i=iter[v];i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to])
			{
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0)
				{
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}

	//求解从s到t的最大流
	int max_flow(int s,int t)
	{
		int flow=0;
		for(;;)
		{
			bfs(s);
			if(level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			int f;
			while((f=dfs(s,t,INF))>0) flow+=f;
		}
	}
}ans;

vector<int> G[MAX_V];
int de[MAX_V],cap[MAX_V][MAX_V];

bool check(int flow,int n)
{
    int s=0,t=n+1,S=n+2,T=n+3;
    ans.init(T);
    for(int i=1;i<=n;i++)
    {
        ans.add(s,i,INF);
        ans.add(i,t,INF);
        for(int j=0;j<G[i].size();j++)
            ans.add(i,G[i][j],INF);
    }
    ans.add(t,s,flow);
    int sum=0;
    for(int i=1;i<=n;i++)
        if(de[i]>0) ans.add(S,i,de[i]),sum+=de[i];
        else if(de[i]<0) ans.add(i,T,-de[i]);
    return ans.max_flow(S,T)==sum;
}

int a[MAX_V];

bool dfs(int u,int dep,int t)
{
    a[dep]=u;
    if(u==t)
    {
        //printf("%d",dep-1);
        for(int i=1;i<dep;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",a[i]);
        }

        printf("\n");
        return true;
    }
    for(int v=1;v<=t;v++)
    {
        if(cap[u][v])
        {
            cap[u][v]--;
            if(dfs(v,dep+1,t)) return true;
        }
    }
    return false;
}

int main()
{
    int n,m,v;
    while(scanf("%d",&n)!=EOF)
    {
        memset(de,0,sizeof de);
        memset(cap,0,sizeof cap);
        int s=0,t=n+1;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&v);
                G[i].push_back(v);
                cap[i][v]=1;
                de[i]--;
                de[v]++;
            }
        }
        int l=0,r=INF,mid,res;
        while(r>=l)
        {
            mid=(l+r)/2;
            if(check(mid,n)) r=mid-1,res=mid;
            else l=mid+1;
        }
        printf("%d\n",res);
        check(res,n);
        for(int u=0;u<=n;u++)
        {
            for(int j=0;j<ans.G[u].size();j++)
            {
                edge& e=ans.G[u][j];
                int v=e.to;
                if(u!=s&&v!=t&&cap[u][v]==0||v>n+1) continue;
                int tmp=INF-e.cap+1;
                if(u==s||j==t) tmp--;
                cap[u][v]=tmp;
            }
        }
        for(int u=1;u<=n;u++)
            while(cap[s][u]>0)
            {
                //printf("*%d %d\n",u,cap[s][u]);
                cap[s][u]--;
                dfs(u,1,t);
            }

    }
    return 0;
}
