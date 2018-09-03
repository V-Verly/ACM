#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=5e4+10;
int a[maxn],tree[4*maxn],lazy[4*maxn];

void up(int rt)
{
    tree[rt]=tree[rt*2]+tree[rt*2+1];
    lazy[rt]=lazy[rt*2]||lazy[rt*2+1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=a[l];
        lazy[rt]=(tree[rt]>1);
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    up(rt);
}

void update(int l,int r,int rt,int x,int y)
{
    if(!lazy[rt]) return;
    if(l==r)
    {
        tree[rt]=sqrt(tree[rt]);
        lazy[rt]=(tree[rt]>1);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt*2,x,y);
    if(y>mid) update(mid+1,r,rt*2+1,x,y);
    up(rt);
}

int query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return tree[rt];
    int mid=(l+r)>>1,ans=0;
    if(x<=mid) ans+=query(l,mid,rt*2,x,y);
    if(y>mid) ans+=query(mid+1,r,rt*2+1,x,y);
    return ans;
}

int main()
{
    int n,op,l,r,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&op,&l,&r,&c);
        if(!op)
            update(1,n,1,l,r);
        else
            printf("%d\n",query(1,n,1,l,r));
    }
    return 0;
}
