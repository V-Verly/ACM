#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2000+10;
const int inf=0x3f3f3f3f;
char a[2100][10];
int n,cost[maxn][maxn];
int mincost[maxn];
bool vis[maxn];

int cal(char m[],char n[])
{
    int ans=0;
    for(int i=0;i<7;i++)
        if(m[i]!=n[i]) ans++;
    return ans;
}

void prim()
{
    for(int i=0;i<n;i++)
        mincost[i]=cost[i][0],vis[i]=false;
    mincost[0]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!vis[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        res+=mincost[v];
        vis[v]=true;
        for(int u=0;u<n;u++)
            if(!vis[u]) mincost[u]=min(mincost[u],cost[u][v]);
    }
    printf("The highest possible quality is 1/%d.\n",res);
}

int main()
{

    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(a,0,sizeof(a));
        memset(cost,0,sizeof(cost));
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
                cost[i][j]=cost[j][i]=cal(a[i],a[j]);
            cost[i][i]=inf;
        }
        prim();
    }
    return 0;
}
