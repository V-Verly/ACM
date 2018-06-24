#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=1e5+10;
long long a[maxn];
long long tree[4*maxn],num[4*maxn];

void build(int l,int r,int rt)
{
    if(l==r) {tree[rt]=a[l];return; }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}

void update(int l,int r,int rt,int ll,int rr)
{
    if(tree[rt]==r-l+1) return;
    if(l==r)
    {
        tree[rt]=(long long)sqrt(tree[rt]);
        return;
    }
    int mid=(l+r)/2;
    if(ll<=mid) update(l,mid,rt*2,ll,rr);
    if(rr>mid) update(mid+1,r,rt*2+1,ll,rr);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}

long long query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr) return tree[rt];
    int mid=(l+r)/2;
    long long ans=0;
    if(ll<=mid) ans+=query(l,mid,rt*2,ll,rr);
    if(rr>mid) ans+=query(mid+1,r,rt*2+1,ll,rr);
    return ans;
}

int main()
{
    int n,m,c=0;
    while(~scanf("%d",&n))
    {
        printf("Case #%d:\n",++c);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        build(1,n,1);
        scanf("%d",&m);
        int t,x,y;
        while(m--)
        {
            scanf("%d%d%d",&t,&x,&y);
            if(x>y) swap(x,y);
            if(t==0) update(1,n,1,x,y);
            else printf("%lld\n",query(1,n,1,x,y));
        }
        printf("\n");
    }
    return 0;
}
