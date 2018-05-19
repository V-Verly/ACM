#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
int w[1005][1005];

int main()
{
    int t,n,st,en,l,v[1005],d[1005];
    while(scanf("%d%d",&t,&n)!=EOF)
    {
        memset(w,inf,sizeof(w));
        memset(v,0,sizeof(v));
        while(t--)
        {
            scanf("%d%d%d",&st,&en,&l);
            w[st][en]=min(w[st][en],l);
            w[en][st]=min(w[en][st],l);
        }
        for(int i=1;i<=n-1;i++) d[i]=inf;
        d[n]=0;
        for(int i=1;i<=n;i++)
        {
            int x,m=inf;
            for(int y=1;y<=n;y++)
                if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=1;
            for(int y=1;y<=n;y++)
                d[y]=min(d[y],d[x]+w[x][y]);
        }
        printf("%d\n",d[1]);
    }
    return 0;
}
