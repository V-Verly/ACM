#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long C[15][15];

long long det(int n)
{
    long long ret=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            while(C[j][i])
            {
                long long t=C[i][i]/C[j][i];
                for(int k=i;k<=n;k++)
                    C[i][k]=(C[i][k]-C[j][k]*t);
                for(int k=i;k<=n;k++)
                    swap(C[i][k],C[j][k]);
                ret=-ret;
            }
        if(!C[i][i])
            return 0;
        ret=ret*C[i][i];
    }
    return ret>0?ret:-ret;
}

int main()
{
    int t,n,m,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(C,0,sizeof C);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            C[u][u]++;C[v][v]++;
            C[u][v]--;C[v][u]--;
        }
        printf("%lld\n",det(n));
    }
    return 0;
}
