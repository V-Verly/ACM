#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
int node[20],edge[20][20];
int p[20],ans[20],mincost[20];
double minradio;
bool vis[20];
int m,n;

int prim()
{
    for(int i=0;i<m;i++)
        mincost[p[i]]=edge[p[i]][p[0]],vis[p[i]]=false;
    mincost[p[0]]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int r=0;r<m;r++)
            if(!vis[p[r]]&&(v==-1||mincost[p[r]]<mincost[p[v]])) v=r;
        if(v==-1) break;
        res+=mincost[p[v]];
        vis[p[v]]=true;

        for(int r=0;r<m;r++)
            if(!vis[p[r]]) mincost[p[r]]=min(mincost[p[r]],edge[p[v]][p[r]]);
    }
    return res;
}

void dfs(int cur,int num)
{
    if(cur==m)
    {
        int sum=0;
        for(int i=0;i<m;i++)
            sum+=node[p[i]];

        int e=prim();

        double radio=e*1.0/sum;
        if(radio<minradio)
        {
            minradio=radio;
            for(int i=0;i<m;i++)
                ans[i]=p[i];
        }
        return;
    }
    if(n-cur+num<m) return;
    for(int i=num+1;i<=n;i++)
    {
        p[cur]=i;
        dfs(cur+1,i);
    }
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        minradio=inf;
        for(int i=1;i<=n;i++)
            scanf("%d",&node[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&edge[i][j]);
        for(int i=1;i<=n;i++)
            edge[i][i]=inf;
        for(int i=1;i<=n;i++)
        {
            p[0]=i;
            dfs(1,i);
        }

        for(int i=0;i<m;i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
