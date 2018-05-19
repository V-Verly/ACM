#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d[205][2],n,m;
double c[205],r[205];

bool Bellman_Ford(int st,double v)
{
    double q[105];
    for(int i=1;i<=n;i++)
        q[i]=0;
    q[st]=v;
    for(int k=0;k<n-1;k++)
    {
        for(int i=0;i<2*m;i++)
        {
            int x=d[i][0],y=d[i][1];
                q[y]=max(q[y],(q[x]-c[i])*r[i]);
        }
    }
    for(int i=0;i<2*m;i++)
    {
        int x=d[i][0],y=d[i][1];
        if(q[y]<(q[x]-c[i])*r[i]) return true;
    }
    return false;
}

int main()
{
    int s,a,b;
    double v,e,f,g,h;
    while(scanf("%d%d%d%lf",&n,&m,&s,&v)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&e,&f,&g,&h);
            d[i*2][0]=a;
            d[i*2][1]=b;
            r[i*2]=e;
            c[i*2]=f;
            d[i*2+1][0]=b;
            d[i*2+1][1]=a;
            r[i*2+1]=g;
            c[i*2+1]=h;
        }
        if(Bellman_Ford(s,v)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
