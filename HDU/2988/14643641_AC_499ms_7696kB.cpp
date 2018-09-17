#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=4e5+10;
struct edge {int u,v;long long cost;}es[maxn];
int pre[maxn];

int Find(int x) {return pre[x]==x?x:pre[x]=Find(pre[x]);}

bool cmp(const edge& e1,const edge& e2)
{
    return e1.cost<e2.cost;
}

int V,E;

long long kruskal()
{
    sort(es,es+E,cmp);
    long long res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        int fx=Find(e.u),fy=Find(e.v);
        if(fx!=fy) pre[fx]=fy,res+=e.cost;
    }
    return res;
}

int main()
{
    int u,v;
    long long sum,w;
    while(scanf("%d%d",&V,&E)!=EOF&&(V||E))
    {
        for(int i=0;i<V;i++) pre[i]=i;
        sum=0;
        for(int i=0;i<E;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            es[i<<1].u=es[i<<1|1].v=u;
            es[i<<1].v=es[i<<1|1].u=v;
            es[i<<1].cost=es[i<<1|1].cost=w;
            sum+=w;
        }
        E*=2;
        printf("%lld\n",sum-kruskal());
    }
    return 0;
}
