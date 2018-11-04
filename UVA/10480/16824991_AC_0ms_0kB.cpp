#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V=200+10;
const int INF=0x3f3f3f3f;

int n,m,g[55][55],flow[55][55];
int p[55],a[55],x[550],y[550],f;

int maxflow()
{
    queue<int> q;
    memset(flow,0,sizeof flow);
    f=0;
    for(;;)
    {
        memset(a,0,sizeof a);
        a[1]=INF;
        q.push(1);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int v=1;v<=n;v++)
                if(!a[v]&&flow[u][v]<g[u][v])
                {
                    p[v]=u;
                    a[v]=min(a[u],g[u][v]-flow[u][v]);
                    q.push(v);
                }
        }
        if(a[2]==0) break;
        for(int u=2;u!=1;u=p[u])
        {
            flow[p[u]][u]+=a[2];
            flow[u][p[u]]-=a[2];
        }
        f+=a[2];
    }
    return f;
}

int main()
{
    int u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF&&(n&&m))
    {
        memset(g,0,sizeof g);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            x[i]=u,y[i]=v;
            g[u][v]=g[v][u]=w;
        }
        maxflow();
        for(int i=0;i<m;i++)
            if((!a[x[i]]&&a[y[i]])||(a[x[i]]&&!a[y[i]]))
                printf("%d %d\n",x[i],y[i]);
        printf("\n");
    }
    return 0;
}
