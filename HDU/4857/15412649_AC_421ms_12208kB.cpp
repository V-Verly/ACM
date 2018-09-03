#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int maxn=3e4+10;
const int maxm=1e5+10;

vector<int> edge[maxm];
map<int,int> mp[maxn];
int n,indegree[maxn],ans[maxn],cnt;

void add(int u,int v)
{
    edge[v].push_back(u);
    indegree[u]++;
}

struct num
{
    int n;
    bool operator <(const num &t) const
    {
        return n<t.n;
    }
};

void Toposort()
{
    priority_queue< num > que;
    for(int i=1;i<=n;i++)
        if(!indegree[i]) que.push({i});
    while(!que.empty())
    {
        num f=que.top();
        int u=f.n;
        que.pop();
        indegree[u]-=1;
        ans[cnt++]=u;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            indegree[v]--;
            if(!indegree[v]) que.push({v});
        }
    }
}


int main()
{
    int t,m,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            edge[i].clear(),mp[i].clear(),indegree[i]=0;
        cnt=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(!mp[u].count(v))
            {
                add(u,v);
                mp[u][v]=1;
            }
        }
        if(n==1) {printf("1\n");continue;}
        Toposort();
        for(int i=n-1;i>=0;i--)
        {

            printf("%d",ans[i]);
            if(i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
