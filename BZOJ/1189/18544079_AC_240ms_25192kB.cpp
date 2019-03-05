#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,cnt1=1,cnt2=1;
char mp[25][25];
bool vis[25][25];
int p[405],d[405],cost[405][405];

int cal(int x,int y) {return x*m+y; }

struct node{ int x,y,step; };

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

bool ok(int x,int y) {
    return x<0||x>=n||y<0||y>=m||vis[x][y]||mp[x][y]!='.';
}

void bfs(int x,int y)
{
    queue<node> que;
    que.push(node{x,y,0});
    memset(vis,false,sizeof vis);
    vis[x][y]=1;
    while(!que.empty())
    {
        node f=que.front();
        que.pop();
        if(mp[f.x][f.y]=='.') cost[p[cal(f.x,f.y)]][d[cal(x,y)]]=f.step;
        for(int i=0;i<4;i++)
        {
            int fx=f.x+dx[i],fy=f.y+dy[i];
            if(ok(fx,fy)) continue;
            que.push(node{fx,fy,f.step+1});
            vis[fx][fy]=true;
        }
    }
}

const int MAX_V=50000+10;
const int INF=0x3f3f3f3f;

//用于表示边的结构体（终点，流量，反向边）
struct edge{int to,cap,rev;};

vector<edge> G[MAX_V];	//图的邻接表表示
int level[MAX_V];	//顶点到源点的距离标号
int iter[MAX_V];	//当前弧

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

int S,T;

bool check(int x)
{
    for(int i=0;i<=T;i++) G[i].clear();
    for(int i=1;i<=cnt1;i++) add(S,i,1);
    for(int i=1;i<=cnt2;i++)
        for(int j=1;j<=x;j++) add(cnt1+(i-1)*x+j,T,1);
    for(int i=1;i<=cnt1;i++)
        for(int j=1;j<=cnt2;j++)
            if(cost[i][j]!=-1&&cost[i][j]<=x)
                for(int k=cost[i][j];k<=x;k++)
                    add(i,cnt1+(j-1)*x+k,1);
    return max_flow(S,T)==cnt1;
}

int main()
{

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='.') p[cal(i,j)]=cnt1++;
            else if(mp[i][j]=='D') d[cal(i,j)]=cnt2++;
    memset(cost,0xff,sizeof cost);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='D') bfs(i,j);
    cnt1--;cnt2--;
    S=0,T=cnt1+cnt2*400+1;
    int l=0,r=400,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    if(~ans) printf("%d\n",ans);
    else printf("impossible\n");
    return 0;
}
