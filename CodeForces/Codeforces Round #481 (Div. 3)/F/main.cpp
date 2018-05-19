#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
int w[maxn];

struct P{
int n,r,s;
}p[maxn];

bool cmpa(const P &a,const P &b)
{
    return a.r<b.r;
}

bool cmpb(const P &a,const P &b)
{
    return a.n<b.n;
}

int main()
{
    int n,k,u,v;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].r);
        p[i].n=i;
    }

    memset(w,0,sizeof(w));
    while(k--)
    {
        scanf("%d%d",&u,&v);
        if(p[u-1].r>p[v-1].r) w[u-1]++;
        else if(p[u-1].r<p[v-1].r) w[v-1]++;
    }
    sort(p,p+n,cmpa);
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(i&&p[i].r>p[i-1].r) t=i;
        p[i].s=t;
    }
    sort(p,p+n,cmpb);
    for(int i=0;i<n;i++)
        printf("%d ",p[i].s-w[i]);
    return 0;
}
