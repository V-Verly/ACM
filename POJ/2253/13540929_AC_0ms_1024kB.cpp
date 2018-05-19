#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int inf=0x3f3f3f3f;

int main()
{
    int n,x[205],y[205],count=0;
    double w[205][205],d[205],l;
    bool v[205];
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(w,0,sizeof(w));
        memset(v,false,sizeof(v));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=0;j<i;j++)
            {
                l=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
                w[i][j]=max(w[i][j],l);
                w[j][i]=max(w[j][i],l);
            }
        }
        for(int i=1;i<n;i++)
            d[i]=inf;
        d[0]=0;
        for(int i=0;i<n;i++)
        {
            int x,m=inf;
            for(int y=0;y<n;y++)
                if(!v[y]&&d[y]<=m) m=d[x=y];
            v[x]=true;
            for(int y=0;y<n;y++)
                d[y]=min(d[y],max(d[x],w[x][y]));
        }
        if(count++) printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3f\n",count,d[1]);
    }
    return 0;
}
