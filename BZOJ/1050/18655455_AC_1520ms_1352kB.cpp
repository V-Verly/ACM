#include <bits/stdc++.h>

using namespace std;

const int maxn=500+10;

int pre[maxn];

struct Edge
{
    int u,v,w;
    bool operator<(const Edge &e) const { return w<e.w; }
} es[10*maxn];

int Find(int x) { return x==pre[x]?x:pre[x]=Find(pre[x]); }

int main()
{
    int n,m,s,t,u,v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
    scanf("%d%d",&s,&t);
    sort(es,es+m);
    int x=1,y=30010;
    for(int st=0,en;st<m;st++)
    {
        for(int i=1;i<=n;i++) pre[i]=i;
        for(int i=st;i<m;i++)
        {
            u=es[i].u,v=es[i].v;
            if(u==v) continue;
            int fx=Find(u),fy=Find(v);
            if(fx!=fy) pre[fx]=fy;
            if(Find(s)==Find(t))
            {
                en=i;
                int tx=es[st].w,ty=es[en].w;
                if(x*ty<tx*y) x=tx,y=ty;
                break;
            }
        }
        if(Find(s)!=Find(t)) break;
        for(int i=1;i<=n;i++) pre[i]=i;
        for(int i=en;i>=st;i--)
        {
            u=es[i].u,v=es[i].v;
            if(u==v) continue;
            int fx=Find(u),fy=Find(v);
            if(fx!=fy) pre[fx]=fy;
            if(Find(s)==Find(t))
            {
                int tx=es[st].w,ty=es[en].w;
                if(x*ty<tx*y) x=tx,y=ty;
                break;
            }
        }

    }
    if(y==30010) return 0*printf("IMPOSSIBLE\n");
    int g=__gcd(x,y);
    x/=g,y/=g;
    if(x>1) printf("%d/%d\n",y,x);
    else printf("%d\n",y);
    return 0;
}
