#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=1e6+10;

int w[1005][1005];

int main()
{
    int t,n,m,st,en,l,v[1005],d[1005],count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&st,&en,&l);
            w[st][en]=max(w[st][en],l);
            w[en][st]=max(w[en][st],l);
        }
        for(int i=1;i<=n;i++)
            d[i]=w[1][i];
        for(int i=1;i<=n;i++)
        {
            int x,m=0;
            for(int y=1;y<=n;y++)
                if(!v[y]&&d[y]>m) m=d[x=y];
            v[x]=1;
            for(int y=1;y<=n;y++)
                d[y]=max(d[y],min(d[x],w[x][y]));
        }
        printf("Scenario #%d:\n%d\n\n",++count,d[n]);
    }
    return 0;
}