#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5;
struct edge {int u,v,cost;}es[maxn];
int pre[maxn];

int Find(int x)  {return pre[x]==x?x:pre[x]=Find(pre[x]);}

bool cmp(const edge& e1,const edge& e2)
{
    return e1.cost<e2.cost;
}

int V,E;

int kruskal()
{
    sort(es,es+E,cmp);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        int fx=Find(e.u);
        int fy=Find(e.v);
        if(fx!=fy) {pre[fx]=fy;res+=e.cost;}
    }
    return res;
}

int main()
{
    while(scanf("%d",&V)!=EOF&&V)
    {
        for(int i=1;i<=V;i++) pre[i]=i;
        scanf("%d",&E);
        for(int i=0;i<E;i++)
            scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
        printf("%d\n",kruskal());
    }
    return 0;
}
