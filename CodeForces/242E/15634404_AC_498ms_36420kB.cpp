#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int a[maxn];
int s[maxn<<2][22],lazy[maxn<<2];

void up(int rt)
{
    for(int i=0;i<=20;i++)
        s[rt][i]=s[rt<<1][i]+s[rt<<1|1][i];
}

void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        for(int i=0;i<=20;i++)
            s[rt][i]=(a[l]&(1<<i))>0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    up(rt);
}

void down(int l,int r,int rt)
{
    int mid=(l+r)>>1;
    if(!lazy[rt]) return;
    for(int i=0;i<=20;i++)
    {
        if(lazy[rt]&(1<<i))
        {
            s[rt<<1][i]=mid-l+1-s[rt<<1][i];
            s[rt<<1|1][i]=r-mid-s[rt<<1|1][i];
        }
    }
    lazy[rt<<1]^=lazy[rt];
    lazy[rt<<1|1]^=lazy[rt];
    lazy[rt]=0;
}

void update(int l,int r,int rt,int x,int y,int p)
{
    if(x<=l&&r<=y)
    {
        for(int i=0;i<=20;i++)
            if(p&(1<<i)) s[rt][i]=r-l+1-s[rt][i];
        lazy[rt]^=p;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt<<1,x,y,p);
    if(y>mid) update(mid+1,r,rt<<1|1,x,y,p);
    up(rt);
}

long long query(int l,int r,int rt,int x,int y)
{
    long long ans=0;
    if(x<=l&&r<=y)
    {
        for(int i=0;i<=20;i++)
            ans+=(1ll<<i)*s[rt][i];
        return ans;
    }
    down(l,r,rt);
    int mid=(l+r)>>1;
    if(x<=mid) ans+=query(l,mid,rt<<1,x,y);
    if(y>mid) ans+=query(mid+1,r,rt<<1|1,x,y);
    up(rt);
    return ans;
}

int main()
{
    int n,q,op,l,r,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,n,1,l,r));
        }
        else
        {
            scanf("%d%d%d",&l,&r,&x);
            update(1,n,1,l,r,x);
        }
    }
    return 0;
}
