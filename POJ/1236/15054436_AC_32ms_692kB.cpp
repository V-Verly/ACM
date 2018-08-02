#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int maxn=100+10;
vector<int> edge[maxn];
stack<int> st;

int dfn[maxn],low[maxn],tot;
int sccno[maxn],scc,in[maxn],out[maxn];
bool instack[maxn];

void Tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    st.push(u);
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
        scc++;
        do
        {
            v=st.top();st.pop();
            instack[v]=false;
            sccno[v]=scc;
        }while(u!=v);
    }
}

int main()
{
    int n,u,v;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            edge[i].clear();
        for(u=1;u<=n;u++)
        {
            while(scanf("%d",&v)==1&&v)
                edge[u].push_back(v);
        }
        memset(dfn,0,sizeof(dfn));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        tot=scc=0;
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(u=1;u<=n;u++)
        {
            for(int i=0;i<edge[u].size();i++)
            {
                v=edge[u][i];
                if(sccno[u]!=sccno[v])
                {
                    out[sccno[u]]++;
                    in[sccno[v]]++;
                }
            }
        }
        int a=0,b=0;
        for(int i=1;i<=scc;i++)
        {
            if(in[i]==0) a++;
            if(out[i]==0) b++;
            //printf("%d %d\n",in[i],out[i]);
        }
        int ans=max(a,b);
        if(scc==1) printf("1\n0\n");
        else printf("%d\n%d\n",a,ans);

    }
    return 0;
}
