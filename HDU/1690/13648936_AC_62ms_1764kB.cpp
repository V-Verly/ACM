#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const long long inf=1e12;

int main()
{
    long long l1,l2,l3,l4,c1,c2,c3,c4;
    long long m,n,t,d[105][105],map[105],count=0;
    scanf("%lld",&t);
    while(t--)
    {
        printf("Case %lld:\n",++count);
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
        scanf("%lld%lld",&n,&m);
        memset(d,inf,sizeof(d));
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&map[i]);
            for(int j=1;j<i;j++)
            {
                long long l=abs(map[i]-map[j]);
                if(l<=l1) d[i][j]=d[j][i]=c1;
                else if(l<=l2) d[i][j]=d[j][i]=c2;
                else if(l<=l3) d[i][j]=d[j][i]=c3;
                else if(l<=l4) d[i][j]=d[j][i]=c4;
                else d[i][j]=d[j][i]=inf;
            }
            d[i][i]=0;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    //if(d[i][j]<inf&&d[k][j]<inf)
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        while(m--)
        {
            long long st,en;
            scanf("%lld%lld",&st,&en);
            if(d[st][en]<inf) printf("The minimum cost between station %lld and station %lld is %lld.\n",st,en,d[st][en]);
            else printf("Station %lld and station %lld are not attainable.\n",st,en);
        }
    }
    return 0;
}
