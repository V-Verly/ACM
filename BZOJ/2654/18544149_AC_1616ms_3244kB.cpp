#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

struct Edge
{
    int u,v,w,col;
    bool operator<(const Edge &e)const {
        return w==e.w?col<e.col:w<e.w;
    }
}edge[maxn];

int n,m,lim,tot,cnt,pre[maxn];

int Find(int x){return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

bool check(int x)
{
    for(int i=0;i<n;i++) pre[i]=i;
    for(int i=0;i<m;i++) if(!edge[i].col) edge[i].w+=x;
    tot=cnt=0;
    sort(edge,edge+m);
    for(int i=0;i<m;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        if(Union(u,v))
        {
            tot+=edge[i].w;
            if(!edge[i].col) cnt++;
        }
    }
    for(int i=0;i<m;i++) if(!edge[i].col) edge[i].w-=x;
    return cnt>=lim;
}

int main()
{
    scanf("%d%d%d",&n,&m,&lim);
    for(int i=0;i<m;i++)
        scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w,&edge[i].col);
    int l=-105,r=105,mid,ans;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1,ans=tot-lim*mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
