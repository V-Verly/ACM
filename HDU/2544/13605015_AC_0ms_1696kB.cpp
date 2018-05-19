#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;

int main()
{
    int n,m,d[105],w[105][105],a,b,l;
    bool v[105];
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(w,inf,sizeof(w));
        memset(v,false,sizeof(v));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&l);
            w[a][b]=w[b][a]=min(w[a][b],l);
        }
        memset(d,inf,sizeof(d));
        d[1]=0;
        for(int i=0;i<n;i++)
        {
            int x,m=inf;
            for(int y=1;y<=n;y++)
                if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=true;
            for(int y=1;y<=n;y++)
                d[y]=min(d[y],d[x]+w[x][y]);
        }
        printf("%d\n",d[n]);
    }
    return 0;
}
