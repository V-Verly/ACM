#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=10000;

int main()
{
    int w[105][105],d[105],n,t,a,st,en;
    bool v[105];
    while(scanf("%d%d%d",&n,&st,&en)!=EOF)
    {
        memset(w,inf,sizeof(w));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(int j=0;j<t;j++)
            {
                scanf("%d",&a);
                w[i][a]=j?1:0;
            }
        }
        memset(v,false,sizeof(v));
        for(int i=1;i<=n;i++) d[i]=i==st?0:inf;
        for(int i=0;i<n;i++)
        {
            int x,m=inf;
            for(int y=1;y<=n;y++)
                if(!v[y]&&d[y]<=m) m=d[x=y];
            for(int y=1;y<=n;y++)
                d[y]=min(d[y],d[x]+w[x][y]);
            v[x]=true;
        }
        if(d[en]==inf) printf("-1\n");
        else printf("%d\n",d[en]);
    }
    return 0;
}
