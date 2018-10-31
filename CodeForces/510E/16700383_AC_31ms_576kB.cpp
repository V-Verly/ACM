#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V=200+10;
const int INF=0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edge{int to,cap,rev;};

vector<edge> G[MAX_V];	//图的邻接表表示
int level[MAX_V];	//顶点到源点的距离标号
int iter[MAX_V];	//当前弧
vector<int> es[MAX_V];

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

bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int n,a[205],link[205][2],ans[205][205];
    bool vis[205]={0};
    scanf("%d",&n);
    int s=0,t=n+1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2) add(s,i,2);
        else add(i,t,2),cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(isprime(a[i]+a[j]))
            {
                if(a[i]%2) add(i,j,1),es[i].push_back(G[i].size()-1);
                else add(j,i,1),es[j].push_back(G[j].size()-1);
            }
        }
    }
    if(max_flow(s,t)!=cnt*2) return 0*printf("Impossible\n");
     vector<int> v;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        if(a[i]%2)
        {
            for(int j=0;j<es[i].size();j++)
                if(G[i][es[i][j]].cap==0)
                    link[i][cnt++]=G[i][es[i][j]].to;
            v.push_back(i);
        }
    }
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        int cnt=1,st=v[i],en;
        if(vis[st]) continue;
        ans[sum][cnt++]=st;
        int now=link[st][0];
        vis[st]=1;
        while(now!=link[st][1])
        {
            ans[sum][cnt++]=now;
            for(int j=i+1;j<v.size();j++)
            {
                if(vis[v[j]]) continue;
                if(link[v[j]][0]==now)
                {
                    now=link[v[j]][1];
                    ans[sum][cnt++]=v[j];
                    vis[v[j]]=1;
                    break;
                }
                else if(link[v[j]][1]==now)
                {
                    now=link[v[j]][0];
                    ans[sum][cnt++]=v[j];
                    vis[v[j]]=1;
                    break;
                }
            }
        }
        ans[sum][cnt++]=now;
        ans[sum++][0]=cnt;
    }
    printf("%d\n",sum);
    for(int i=0;i<sum;i++)
    {
        printf("%d",ans[i][0]-1);
        for(int j=1;j<ans[i][0];j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
    return 0;
}
