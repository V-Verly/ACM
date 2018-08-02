#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int maxn=5000+10;

int dfn[maxn],low[maxn],tot;
int degree[maxn],bccno[maxn],bcc_cnt;
bool instack[maxn]={false};

vector <int> edge[maxn];
stack <int> st;

void Tarjan(int u,int fa)
{
    low[u]=dfn[u]=++tot;
    st.push(u);
    instack[u]=true;
    int v;
    bool flag=false;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(!flag&&v==fa)
        {
            flag=true;
            continue;
        }
        if(!dfn[v])
        {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        bcc_cnt++;
        do
        {
            v=st.top();st.pop();
            bccno[v]=bcc_cnt;
            instack[v]=false;
        }while(v!=u);
    }
}

int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        memset(dfn,0,sizeof(dfn));
        memset(degree,0,sizeof(degree));
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i,0);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(bccno[v]!=bccno[u])
                {
                    degree[bccno[u]]++;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=bcc_cnt;i++)
        {
            if(degree[i]==1) ans++;
        }
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}
