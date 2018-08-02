#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int maxn=1000+10;

int n;
int low[maxn],dfn[maxn],tot;
int bccno[maxn],bcc_cnt;
bool G[maxn][maxn],instack[maxn];
bool ok[maxn],can[maxn];
int tmp[maxn];
int color[maxn];

stack <int> st;

bool dfs(int u,int col)
{
    color[u]=col;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v])
        {
            if(!ok[v]) continue;
            if(color[v]!=-1)
            {
                if(color[v]==col) return false;
                continue;
            }
            if(!dfs(v,!col)) return false;
        }
    }
    return true;
}

void Tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tot;
    st.push(u);
    instack[u]=true;
    bool flag=false;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v])
        {
            if(v==fa&&!flag){flag=true;continue;}
            if(!dfn[v])
            {
                Tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u])
                {
                    bcc_cnt++;
                    int x,index=0;
                    memset(ok,false, sizeof(ok));
                    do
                    {
                        x=st.top();st.pop();
                        bccno[x]=bcc_cnt;
                        instack[x]=false;
                        ok[x]=true;
                        tmp[index++]=x;
                    }while(x!=v);
                    ok[u]=true;
                    memset(color,0xff,sizeof(color));
                    if(!dfs(u,0))
                    {
                        can[u]=true;
                        while(index--) can[tmp[index]]=true;
                    }
                }
            }
            else if(instack[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    int m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(G,true,sizeof(G));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            G[u][v]=G[v][u]=false;
        }
        for(int i=1;i<=n;i++)
            G[i][i]=0;
        memset(dfn,0,sizeof(dfn));
        tot=bcc_cnt=0;
        memset(can,false,sizeof(can));
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i,0);
        int ans=n;
        for(int i=1;i<=n;i++)
            if(can[i])
                ans--;
            printf("%d\n",ans);
    }
    return 0;
}
