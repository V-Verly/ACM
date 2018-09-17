#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int maxn=150+10;
const int inf=0x3f3f3f3f;

int cost[maxn][maxn],dis[maxn],cnt;
bool vis[maxn];

void dijkstra()
{
    for(int i=0;i<cnt;i++) dis[i]=inf;
    memset(vis,false,sizeof(vis));
    dis[0]=0,vis[0]=false;
    for(int i=1;i<cnt;i++)
    {
        int x,m=inf;
        for(int y=0;y<cnt;y++) if(!vis[y]&&dis[y]<m) m=dis[x=y];
        vis[x]=true;
        for(int y=0;y<cnt;y++) if(!vis[y]) dis[y]=min(dis[y],dis[x]+cost[x][y]);
    }
    if(dis[1]<inf) cout<<dis[1]<<endl;
    else cout<<-1<<endl;
}

int main()
{
    int m,w;
    string u,v;
    while(cin>>m&&m!=-1)
    {
        map <string,int> mp;
        memset(cost,inf,sizeof(cost));
        cnt=0;
        cin>>u>>v;
        if(!mp.count(u)) mp[u]=cnt++;
        if(!mp.count(v)) mp[v]=cnt++;
        int s=mp[u],e=mp[v];
        while(m--)
        {
            cin>>u>>v>>w;
            if(!mp.count(u)) mp[u]=cnt++;
            if(!mp.count(v)) mp[v]=cnt++;
            cost[mp[u]][mp[v]]=cost[mp[v]][mp[u]]=min(cost[mp[v]][mp[u]],w);
        }
        if(s==e) cout<<0<<endl;
        else dijkstra();
    }
    return 0;
}
