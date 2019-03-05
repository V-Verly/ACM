#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn=1e5+10;

int head[maxn],cnt=0;
struct Edge {int nex,to; ll w; }edge[20*maxn];

void add_edge(int u,int v,ll w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void add(int u,int v,ll w)
{
    add_edge(u,v,w);
    add_edge(v,u,w);
}

ll _xor[maxn],a[5*maxn],tot=0;
bool vis[maxn]={false};

void dfs(int u)
{
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            _xor[v]=_xor[u]^edge[i].w;
            vis[v]=true;
            dfs(v);
        }
        else
        {
            a[tot++]=_xor[u]^_xor[v]^edge[i].w;
            if(!a[tot-1]) tot--;
        }
    }
}

ll b[70];

void cal()
{
    memset(b,0,sizeof b);
    for(int i=0;i<tot;i++)
    {
        for(int j=63;j>=0;j--)
        {
            if(a[i]>>j&1)
            {
                if(b[j]) a[i]^=b[j];
                else
                {
                    b[j]=a[i];
                    for(int k=j-1;k>=0;k--) if(b[k]&&(b[j]>>k&1)) b[j]^=b[k];
                    for(int k=j+1;k<=63;k++) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
}

int main()
{
    int n,m,u,v;
    ll w;
    scanf("%d%d",&n,&m);
    memset(head,0xff,sizeof head);
    while(m--)
    {
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);
    }
    _xor[1]=0;
    dfs(1);
    cal();
    ll ans=_xor[n];
    for(int i=63;i>=0;i--) if(ans<(ans^b[i])) ans^=b[i];
    printf("%lld\n",ans);
    return 0;
}
