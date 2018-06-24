#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int pre[maxn],tot,head[maxn],vis[maxn],dp[maxn][2];

struct node
{
    int to,nex,w;
    node(){}
    node(int a,int b,int c):to(a),nex(b),w(c){}
}edge[20*maxn];

int Find(int x)
{
    return pre[x]==x?x:pre[x]=Find(pre[x]);
}

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

void add(int u,int v,int w)
{
    edge[tot]=node(v,head[u],w);
    head[u]=tot++;
    edge[tot]=node(u,head[v],w);
    head[v]=tot++;
}

int dfs(int u,int last)
{
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v!=last)
        {
            dfs(v,u);
            int tmp=dp[v][0]+edge[i].w;
            if(tmp>dp[u][0])
            {
                dp[u][1]=dp[u][0];
                dp[u][0]=tmp;
            }
            else if(tmp>dp[u][1])
                dp[u][1]=tmp;
        }
    }
}

int main()
{
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            pre[i]=i;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        tot=0;
        bool flag=false;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(!Union(u,v)) flag=true;
            if(flag) continue;
            add(u,v,w);
        }
        if(flag) printf("YES\n");
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                if(!vis[i]) dfs(i,-1);
            for(int i=1;i<=n;i++)
                if(ans<dp[i][0]+dp[i][1]) ans=dp[i][0]+dp[i][1];
            printf("%d\n",ans);
        }
    }
    return 0;
}
