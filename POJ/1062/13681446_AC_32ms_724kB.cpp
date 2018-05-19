#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
bool v[105];
int w[105][105],m,n,p[105],l[105];

int dijkstra(int st)
{
    int d[105];
    memset(v,false,sizeof(v));
    memset(d,inf,sizeof(d));
    for(int i=1; i<=n; i++)
        d[i]=p[i];
    for(int i=0; i<n; i++)
    {
        int x,mn=inf;
        for(int y=1; y<=n; y++)
            if(!v[y]&&d[y]<mn)  mn=d[x=y];
        v[x]=true;
        if(l[x]<l[st]||l[x]-l[st]>m) continue;
        for(int y=1; y<=n; y++)
            if(!v[y]&&d[y]>d[x]+w[x][y]&&l[y]>=l[st]&&l[y]-l[st]<=m)    d[y]=d[x]+w[x][y];
    }
    return d[1];
}

int main()
{
    int x,u;

    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(w,inf,sizeof(w));
        for(int i=1; i<=n; i++)
        {
            w[i][i]=0;
            scanf("%d%d%d",&p[i],&l[i],&x);
            while(x--)
            {
                scanf("%d",&u);
                scanf("%d",&w[u][i]);
            }
        }
        int ans=inf;
        for(int i=1;i<=n;i++)
            ans=min(ans,dijkstra(i));
        printf("%d\n",ans);
    }
    return 0;
}
