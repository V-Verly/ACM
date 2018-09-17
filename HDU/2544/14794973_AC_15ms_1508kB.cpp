#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;

int main()
{
    int n,m,v[205],d[205],w[205][205],a,b,val;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        memset(v,0,sizeof(v));
        memset(w,inf,sizeof(w));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            w[a][b]=min(w[a][b],val);
            w[b][a]=min(w[b][a],val);
        }
        for(int i=1;i<=n;i++) d[i]=(i==1?0:inf);
        for(int i=1;i<=n;i++)
        {
            int x,m=inf;
            for(int y=1;y<=n;y++) if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=1;
            for(int y=1;y<=n;y++) d[y]=min(d[y],d[x]+w[x][y]);
        }
        printf("%d\n",d[n]);
    }
    return 0;
}
