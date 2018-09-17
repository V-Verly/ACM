#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int maxn=200+10;
const int inf=0x3f3f3f3f;

int n,cnt,cost[maxn][maxn],t[maxn];
bool vis[maxn];

int dijkstra(int u,int v)
{
    for(int i=0;i<cnt;i++) t[i]=cost[u][i],vis[i]=0;
    t[u]=inf;
    for(int i=0;i<cnt;i++)
    {
        int x,m=0;
        for(int y=0;y<cnt;y++)
            if(!vis[y]&&t[y]>=m) m=t[x=y];
        vis[x]=1;
        for(int y=0;y<cnt;y++)
            if(!vis[y]) t[y]=max(t[y],min(t[x],cost[x][y]));
    }
    return t[v];
}

int main()
{
    int m,w,kase=1;
    string u,v;
    map <string,int> mp;
    while(cin>>n>>m&&(n||m))
    {
        mp.clear();
        cnt=0;
        memset(cost,0,sizeof(cost));
        while(m--)
        {
            cin>>u>>v>>w;
            if(!mp.count(u)) mp[u]=cnt++;
            if(!mp.count(v)) mp[v]=cnt++;
            cost[mp[u]][mp[v]]=cost[mp[v]][mp[u]]=w;
        }
        cin>>u>>v;
        int ans=dijkstra(mp[u],mp[v]);
        cout<<"Scenario #"<<kase++<<endl;
        cout<<ans<<" tons"<<endl<<endl;
    }
    return 0;
}
