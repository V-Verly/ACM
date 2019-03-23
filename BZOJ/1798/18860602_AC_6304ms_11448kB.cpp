#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,mod;
ll a[maxn],tree[maxn<<2],add[maxn<<2],tag[maxn<<2];

void pushup(int l,int r,int rt) { tree[rt]=(tree[rt<<1]%mod+tree[rt<<1|1]%mod)%mod; }

void build(int l,int r,int rt)
{
    add[rt]=0, tag[rt]=1;
    if(l==r) {tree[rt]=a[l]%mod; return; }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(l,r,rt);
}

void down(int l,int r,int rt)
{
    if(add[rt]==0&&tag[rt]==1) return ;
    ll ad=add[rt]%mod,tg=tag[rt]%mod;
    int mid=(l+r)>>1;

    (tag[rt<<1]*=tg)%=mod;
    add[rt<<1]=(add[rt<<1]*tg%mod+ad)%mod;
    tree[rt<<1]=(tree[rt<<1]*tg%mod+(ad*(mid-l+1)%mod)%mod)%mod;

    (tag[rt<<1|1]*=tg)%=mod;
    add[rt<<1|1]=(add[rt<<1|1]*tg%mod+ad)%mod;
    tree[rt<<1|1]=(tree[rt<<1|1]*tg%mod+(ad*(r-mid)%mod)%mod)%mod;

    add[rt]=0;
    tag[rt]=1;
}

void mul(int l,int r,int rt,int x,int y,int val)
{
    if(x<=l&&r<=y)
    {
        (tag[rt]*=val)%=mod;
        (add[rt]*=val)%=mod;
        (tree[rt]*=val)%=mod;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)>>1;
    if(x<=mid) mul(l,mid,rt<<1,x,y,val);
    if(y>mid) mul(mid+1,r,rt<<1|1,x,y,val);
    pushup(l,r,rt);
}

void adds(int l,int r,int rt,int x,int y,int val)
{
    if(x<=l&&r<=y)
    {
        (add[rt]+=val)%=mod;
        tree[rt]=(tree[rt]+1ll*val*(r-l+1)%mod)%mod;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)>>1;
    if(x<=mid) adds(l,mid,rt<<1,x,y,val);
    if(y>mid) adds(mid+1,r,rt<<1|1,x,y,val);
    pushup(l,r,rt);
}

ll query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return tree[rt]%mod;
    down(l,r,rt);
    ll ans=0,mid=(l+r)>>1;
    if(x<=mid) (ans+=query(l,mid,rt<<1,x,y))%=mod;
    if(y>mid) (ans+=query(mid+1,r,rt<<1|1,x,y))%=mod;
    pushup(l,r,rt);
    return ans;
}

int main()
{
    int n,m,op,l,r,c;
    scanf("%d%d",&n,&mod);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,n,1);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l,&r,&c);
            mul(1,n,1,l,r,c%mod);
        }
        else if(op==2)
        {
            scanf("%d%d%d",&l,&r,&c);
            adds(1,n,1,l,r,c%mod);
        }
        else if(op==3)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
    return 0;
}
