#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=100+10;

int mp[maxn][maxn],n,s,ans;
int st[maxn],head[maxn],cnt;
bool vis[maxn];

struct Edge
{
    int nex,to;
}edge[1000+10];

void add(int u,int v)
{
    edge[cnt].nex=head[u];
    edge[cnt].to=v;
    head[u]=cnt++;
    mp[u][v]=1;
}

bool check(int u,int tot)
{
    for(int i=0;i<=tot;i++)
        if(!mp[st[i]][u]) return false;
    return true;
}

void dfs(int u,int sum)
{
    st[sum]=u;
    if(sum==s-1) {
        ans++;
        return;
    }
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(check(v,sum)) dfs(v,sum+1);
    }
}

int main()
{
    int t,m,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&s);
        memset(head,0xff,sizeof head);
        memset(mp,0,sizeof mp);
        cnt=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);
            if(mp[u][v]) continue;
            add(u,v);
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            dfs(i,0);
        }
        printf("%d\n",ans);
    }
    return 0;
}
