#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=1000+10;
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

int main()
{
    int T,n,d;
    char mp[25][25],leap[25][25];
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        for(int i=0;i<n;i++)
            scanf("%s",leap[i]);
        int m=strlen(mp[0]);
        int s=0,t=2*m*n+1,p,cnt=0;
        for(int i=0;i<=t;i++)
            G[i].clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(leap[i][j]=='L')
                {
                    p=i*m+j+1;
                    add(s,p,1);
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                p=i*m+j+1;
                if(mp[i][j]-'0')
                {
                    if(i<d||j<d||n-i<=d||m-j<=d)
                    {
                        add(p,t,mp[i][j]-'0');
                        continue;
                    }
                    else add(p,p+n*m,mp[i][j]-'0');
                    for(int x=-d;x<=d;x++)
                    {
                        for(int y=-d;y<=d;y++)
                        {
                            int fx=i+x,fy=j+y;
                            if(fx==i&&fy==j) continue;
                            if(fx<0||fx>=n||fy<0||fy>=m) continue;
                            if(abs(fx-i)+abs(fy-j)>d) continue;
                            if(mp[fx][fy]-'0') add(p+n*m,fx*m+fy+1,INF);
                        }
                    }
                }
            }
        }
        int ans=cnt-max_flow(s,t);
        printf("Case #%d: ",_);
        if(!ans) printf("no lizard was left behind.\n");
        else if(ans==1) printf("1 lizard was left behind.\n");
        else printf("%d lizards were left behind.\n",ans);
    }
    return 0;
}
