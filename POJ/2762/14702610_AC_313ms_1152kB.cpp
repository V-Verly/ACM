#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn=1e4+10;

vector <int> edge[maxn],DAG[maxn];

int dfn[maxn],low[maxn];
int stack[maxn],tot,index;
bool instack[maxn];
int sscno[maxn],ssc,indegree[maxn];

void Tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    stack[++index]=u;
    instack[u]=true;
    int v;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        ssc++;
        do
        {
            v=stack[index--];
            instack[v]=false;
            sscno[v]=ssc;
        }while(u!=v);
    }
}

bool Toposort()
{
    queue<int> que;
    for(int i=1;i<=ssc;i++)
        if(!indegree[i]) que.push(i);
    if(que.size()>1) return false;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        indegree[u]--;
        for(int i=0;i<DAG[u].size();i++)
        {
            int v=DAG[u][i];
            indegree[v]--;
            if(!indegree[v]) que.push(v);
        }
        if(que.size()>1) return false;
    }
    return true;
}

int main()
{
    int m,n,u,v;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            DAG[i].clear();
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(instack,0,sizeof(instack));
        memset(indegree,0,sizeof(indegree));
        index=tot=ssc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(sscno[u]!=sscno[v])
                {
                    DAG[sscno[u]].push_back(sscno[v]);
                    indegree[sscno[v]]++;
                }
            }
        }
        printf("%s\n",Toposort()?"Yes":"No");
    }
    return 0;
}
