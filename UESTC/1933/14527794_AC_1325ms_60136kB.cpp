#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
long long tree[4*maxn],lazy[4*maxn];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=0;
        lazy[rt]=0;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void down(int l,int r,int rt)
{
    if(lazy[rt])
    {
        int mid=(l+r)/2;
        lazy[rt*2]+=lazy[rt];
        tree[rt*2]+=lazy[rt]*(mid-l+1);
        lazy[rt*2+1]+=lazy[rt];
        tree[rt*2+1]+=lazy[rt]*(r-mid);
        lazy[rt]=0;
    }
}

void update(int l,int r,int rt,int x,int y,long long v)
{
    if(x<=l&&r<=y)
    {
        lazy[rt]+=v;
        tree[rt]+=v*(r-l+1);
        return;
    }
    int mid=(l+r)/2;
    down(l,r,rt);
    if(x<=mid) update(l,mid,rt*2,x,y,v);
    if(y>mid) update(mid+1,r,rt*2+1,x,y,v);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}

long long query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y)
    {
        return tree[rt];
    }
    down(l,r,rt);
    int mid=(l+r)/2;
    long long ans=0;
    if(x<=mid) ans+=query(l,mid,rt*2,x,y);
    if(y>mid) ans+=query(mid+1,r,rt*2+1,x,y);
    return ans;
}

int main()
{
    int n,m,o,l,r;
    long long v;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    while(m--)
    {
        scanf("%d%d%d%lld",&o,&l,&r,&v);
        if(o==0)
            update(1,n,1,l,r,v);
        else
            printf("%lld\n",query(1,n,1,l,r));
    }
}
