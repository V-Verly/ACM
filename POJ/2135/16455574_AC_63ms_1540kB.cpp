#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=2000+10;
const int INF=0x3f3f3f3f;

typedef pair<int,int> P;    //first保存最短距离，second保存顶点编号

// 用于表示边的结构体(终点、容量、费用、反向边)
struct edge {int to,cap,cost,rev;};

int V;  //顶点数
vector<edge> G[MAX_V];           //图的邻接表表示
int h[MAX_V];                    //顶点的势
int dist[MAX_V];                 //最短距离
int prevv[MAX_V],preve[MAX_V];   //最短路中的前驱节点和对应的边

//向图中增加一条从from到to容量为cap费用为cost的边
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
};

//求解从s到t流量为f的最小费用流
//如果没有流量为f的流，则返回-1
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);  //初始化h
    while(f>0)
    {
        //使用dijkstra算法更新h
        priority_queue<P,vector<P>,greater<P> > que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top();que.pop();
            int v=p.second;
            //printf("%d %d\n",dist[v],p.first);
            if(dist[v]<p.first) continue;
            for(int i=0;i<G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF) //不能再增广
            return -1;
        for(int v=0;v<V;v++) h[v]+=dist[v];

        //沿s到t的最短路尽量增广
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
            d=min(d,G[prevv[v]][preve[v]].cap);
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}

int main()
{
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int s=0,t=n-1;
        for(int i=0;i<n;i++) G[i].clear();
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u-1,v-1,1,w);
            add_edge(v-1,u-1,1,w);
        }
        V=n;
        printf("%d\n",min_cost_flow(s,t,2));
    }
    return 0;
}