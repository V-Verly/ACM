#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=1000000+10;
const double inf=1e12;

struct Edge
{
    int u,v;
    double w;
    bool operator <(const Edge &e) const {
         return w<e.w;
    }
}edge[maxn];

int pre[1000+10];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

int main()
{
    int n,k;
    double a[1005][2],dx,dy,w;
    int cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i][0],&a[i][1]);
        for(int j=0;j<i;j++)
        {
            dx=a[i][0]-a[j][0];
            dy=a[i][1]-a[j][1];
            w=sqrt(dx*dx+dy*dy);
            edge[cnt].u=j;
            edge[cnt].v=i;
            edge[cnt++].w=w;
        }
    }
    sort(edge,edge+cnt);
    for(int i=0;i<n;i++) pre[i]=i;
    for(int i=0;i<cnt;i++)
    {
        if(Union(edge[i].u,edge[i].v)) n--;
        if(n<k)
        {
            printf("%.2f\n",edge[i].w);
            break;
        }
    }
    return 0;
}
