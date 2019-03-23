#include <bits/stdc++.h>

using namespace std;

int mp[105][105];

vector<int> edge[105];
int indegree[105];

void add(int u,int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
}

double res[105];
bool vis[105];

double dijkstra(int n)
{
	res[0]=1;
	for(int r=1;r<=n;r++)
    {
        int x=-1;
        double m=0;
        for(int i=0;i<n;i++) if(!vis[i]&&res[i]>m) m=res[x=i];
        vis[x]=true;
        for(int i=0;i<n;i++) res[i]=max(res[i],res[x]*mp[x][i]*0.01);
    }
    return res[n-1];
}

int main()
{
    int t,u,v,w,n,m,s,k;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&k);
        for(int i=0;i<n;i++) indegree[i]=res[i]=vis[i]=0,edge[i].clear();
        memset(mp,0,sizeof mp);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=mp[v][u]=w;
        }
        res[0]=1;
        double p=dijkstra(n);
        printf("Case %d: %f\n",_,1.00*s/p*k*2);
    }
    return 0;
}