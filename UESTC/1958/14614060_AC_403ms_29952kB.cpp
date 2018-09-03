#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
vector <int> edge[maxn];
int indegree[maxn]={0},cost[maxn];
bool vis[maxn]={false};

int main()
{
    int n,k,m,a,b;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        indegree[b]++;
    }
    queue <int> que;
    for(int i=1;i<=n;i++)
        if(!indegree[i]) cost[i]=1,que.push(i);
        else cost[i]=inf;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            indegree[v]--;
            cost[v]=min(cost[v],cost[u]+1);
            if(!indegree[v]) que.push(v);
        }
    }
    printf("%d\n",cost[k]);
    return 0;
}
