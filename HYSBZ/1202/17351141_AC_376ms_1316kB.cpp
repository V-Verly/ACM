#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int inf=0x3f3f3f3f;

int n;
int dis[105],in[105];
bool vis[105];

int head[105],cnt;
struct Edge { int nex,to,w; }edge[2000+10];

void add(int u,int v,int w)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

bool SPFA(int S,int T)
{
    queue<int> Q;
    for(int i=S;i<=T;i++)
        Q.push(i),vis[i]=true,in[i]=1,dis[i]=0;
    while(!Q.empty())
    {
        int cur=Q.front();
        Q.pop();
        vis[cur]=false;
        for(int i=head[cur];~i;i=edge[i].nex)
        {
            int v=edge[i].to,w=edge[i].w;
            if(dis[v]<dis[cur]+w)
            {
                dis[v]=dis[cur]+w;
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v]=true;
                    in[v]++;
                    if(in[v]>n) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int t,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof head);
        cnt=0;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u-1,v,w);
            add(v,u-1,-w);
        }
        printf("%s\n",SPFA(0,n)?"true":"false");
    }
    return 0;
}
