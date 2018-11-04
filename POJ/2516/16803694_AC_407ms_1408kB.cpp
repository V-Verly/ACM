#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=100+10;
const int INF=0x3f3f3f3f;
struct Edge//边
{
    int from,to,cap,flow,cost;//出点，入点，容量，当前流量，费用（也就是权值）
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};

struct MCMF
{
    int n,m;
    vector<Edge> edges;//保存表
    vector<int> G[maxn];//保存邻接关系
    int inq[maxn];//判断一个点是否在队列当中（SPFA算法当中要用）
    int d[maxn];//起点到d[i]的最短路径保存值
    int p[maxn];//用来记录路径，保存上一条弧
    int a[maxn];//找到增广路径后的改进量

    void init(int n)//初始化
    {
        this->n=n;
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
    }

    void add_edge(int from,int to,int cap,int cost)//添加边
    {
        edges.push_back(Edge(from,to,cap,0,cost));//正向
        edges.push_back(Edge(to,from,0,0,-cost));//反向
        m=edges.size();
        G[from].push_back(m-2);//按照边的编号保存邻接关系
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,int& flow,long long& cost)//最短路径算法
    {
        for(int i=0;i<=n;i++)
            d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=INF;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)//寻找满足容量大于流量的可松弛边
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])//是否在队列当中
                    {
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF)//如果d[t]没有被更新，相当于没找到增广路径，则没有最大流也没有最小费用
            return false;
        flow+=a[t];//更新最大流
        cost+=(long long )d[t]*(long long)a[t];//单位流量乘以单位路径长度用来计算消耗
        for(int u=t;u!=s;u=edges[p[u]].from)//通过使用p[]保存的上一个边的值来对刚刚找到的增广路径上面的流量进行更新
        {
            edges[p[u]].flow+=a[t];//正向变更新
            edges[p[u]^1].flow-=a[t];//反向变更新（用位运算实现的）
        }
        return true;
    }

    int MincostMaxflow(int s,int t,long long& cost)//计算从s到t的最小消耗cost，返回最大流
    {
        int flow = 0;
        cost=0;
        while(BellmanFord(s,t,flow,cost));//不断寻找最短增广路径，直到找不到为止
        return flow;
    }
}solve;

int main()
{
    int n,m,k;
    int need[55][55],sum[55],good[55][55],cost[55][55][55];
    while(scanf("%d%d%d",&n,&m,&k)!=EOF&&(n&&m&&k))
    {

        int s=0,t=n+m+1,ans=0;
        memset(sum,0,sizeof sum);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&need[i][j]);
                sum[j]+=need[i][j];
            }
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=k;j++)
                scanf("%d",&good[i][j]);
        for(int r=1;r<=k;r++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    scanf("%d",&cost[r][i][j]);

        for(int r=1;r<=k;r++)
        {
            solve.init(t);
            long long c=0;
            for(int i=1;i<=n;i++)
                solve.add_edge(i+m,t,need[i][r],0);
            for(int i=1;i<=m;i++)
                solve.add_edge(s,i,good[i][r],0);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    solve.add_edge(j,i+m,INF,cost[r][i][j]);
            int f=solve.MincostMaxflow(s,t,c);
            if(f!=sum[r]) {ans=-1; break; }
            ans+=c;
        }
        printf("%d\n",ans);
    }
    return 0;
}