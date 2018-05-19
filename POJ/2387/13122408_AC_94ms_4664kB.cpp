#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
int w[1005][1005];

int main()
{
    int t,n,v[1005],d[1005],a,b,i,val;
    while(scanf("%d%d",&t,&n)!=EOF)
    {
        memset(v,0,sizeof(v));
        memset(w,INF,sizeof(w));
        for(i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            w[a][b]=min(w[a][b],val);
            w[b][a]=min(w[b][a],val);
        }
        memset(d,INF,sizeof(d));
        d[n]=0;
        for(i=0;i<n;i++)
        {
            int x,m=INF;
            for(int y=1;y<=n;y++) if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=1;
            for(int y=1;y<=n;y++) d[y]=min(d[y],d[x]+w[x][y]);
        }
        printf("%d\n",d[1]);
    }
    return 0;
}
