#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1000+10;
int n,w[maxn][maxn],p[maxn][maxn],d[1005];

void dijkstra(int st,int r)
{
    int v[1005];
    memset(d,inf,sizeof(d));
    memset(v,0,sizeof(v));
    d[st]=0;
    for(int i=0;i<n;i++)
    {
        int x,m=inf;
        for(int y=1;y<=n;y++)
            if(!v[y]&&d[y]<=m) m=d[x=y];
        v[x]=1;
        for(int y=1;y<=n;y++)
        {
            if(!r) d[y]=min(d[y],d[x]+w[x][y]);
            else d[y]=min(d[y],d[x]+p[x][y]);
        }

    }
}

int main()
{
    int m,x,a,b,l,len[1005];
    while(scanf("%d%d%d",&n,&m,&x)!=EOF)
    {
        memset(w,inf,sizeof(w));
        memset(p,inf,sizeof(p));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&l);
            w[a][b]=min(w[a][b],l);
            p[b][a]=min(p[b][a],l);
        }
        memset(len,0,sizeof(len));
        dijkstra(x,1);
        for(int i=1;i<=n;i++)
            len[i]+=d[i];
        dijkstra(x,0);
        for(int i=1;i<=n;i++)
            len[i]+=d[i];
        int mx=0;
        for(int i=1;i<=n;i++)
            if(mx<len[i]) mx=len[i];
        printf("%d\n",mx);

    }
    return 0;
}