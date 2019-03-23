#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n;
long long a[maxn],tree[maxn<<2],lazy[maxn<<2];

void pushup(int l,int r,int rt)
{
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
    lazy[rt]=lazy[rt<<1]&lazy[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r) {tree[rt]=a[l]; lazy[rt]=(a[l]<=1); return; }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(l,r,rt);
}

void update(int l,int r,int rt,int x,int y)
{
    if(lazy[rt]) return;
    if(l==r)
    {
        tree[rt]=sqrt(tree[rt]);
        lazy[rt]=(tree[rt]<=1);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt<<1,x,y);
    if(mid<y) update(mid+1,r,rt<<1|1,x,y);
    pushup(l,r,rt);
}

long long query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return tree[rt];
    int mid=(l+r)>>1;
    long long ans=0;
    if(x<=mid) ans+=query(l,mid,rt<<1,x,y);
    if(y>mid) ans+=query(mid+1,r,rt<<1|1,x,y);
    return ans;
}

int main()
{
    int n,q,op,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) printf("%lld\n",query(1,n,1,l,r));
        else if(op==2) update(1,n,1,l,r);
    }
    return 0;
}
