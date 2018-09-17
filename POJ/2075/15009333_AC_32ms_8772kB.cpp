#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int maxn=1000+10;
const double inf=1e12;

int n;
double cost[maxn][maxn],mincost[maxn],money;
bool vis[maxn];

void prim()
{
    for(int i=0;i<n;i++)
        mincost[i]=cost[i][0],vis[i]=0;
    mincost[0]=0;
    double res=0;
    for(int i=0;i<n;i++)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            mincost[u]=min(mincost[u],cost[u][v]);
    }
    if(res<=money) cout<<"Need "<<res<<" miles of cable"<<endl;
    else cout<<"Not enough cable"<<endl;
}

int main()
{
    int m;
    string u,v;
    double w;
    map <string,int> mp;
    memset(cost,0x7F,sizeof(cost));
    cin>>money>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u;
        mp[u]=i;
    }
    cin>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        cost[mp[u]][mp[v]]=cost[mp[v]][mp[u]]=w;
    }
    prim();
    return 0;
}
