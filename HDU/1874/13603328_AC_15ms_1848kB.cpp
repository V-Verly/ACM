#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=10000;

int main()
{
    int n,m,v[205],d[205],w[205][205],a,b,val,s,e;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(v,0,sizeof(v));
        memset(w,INF,sizeof(w));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            w[a][b]=min(w[a][b],val);
            w[b][a]=min(w[b][a],val);
        }
        scanf("%d%d",&s,&e);
        for(int i=0;i<n;i++) d[i]=(i==s?0:INF);
        for(int i=0;i<n;i++){
            int x,m=INF;
            for(int y=0;y<n;y++) if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=1;
            for(int y=0;y<n;y++) d[y]=min(d[y],d[x]+w[x][y]);
        }
        if(d[e]!=INF) printf("%d\n",d[e]);
        else printf("-1\n");
    }
    return 0;
}
