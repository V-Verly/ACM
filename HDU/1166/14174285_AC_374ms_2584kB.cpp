#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5e4+10;
int tree[4*maxn],a[maxn];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*rt);
    build(mid+1,r,2*rt+1);
    tree[rt]=tree[2*rt]+tree[2*rt+1];
}

void update(int l,int r,int rt,int p,int x)
{
    if(l==r)
    {
        tree[rt]+=x;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)
        update(l,mid,rt*2,p,x);
    else
        update(mid+1,r,rt*2+1,p,x);
    tree[rt]=tree[2*rt]+tree[2*rt+1];
}

int query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr)
        return tree[rt];
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)
        ans+=query(l,mid,rt*2,ll,rr);
    if(rr>mid)
        ans+=query(mid+1,r,rt*2+1,ll,rr);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int e=1;e<=t;e++)
    {
        printf("Case %d:\n",e);
        int n,l,r,s,m;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        build(1,n,1);
        char q[10];
        while(~scanf("%s",q))
        {
            if(q[0]=='E')
                break;
            if(q[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,n,1,l,r));
            }
            else if(q[0]=='A')
            {
                scanf("%d%d",&m,&s);
                update(1,n,1,m,s);
            }
            else
            {
                scanf("%d%d",&m,&s);
                update(1,n,1,m,-s);
            }
        }
    }
    return 0;
}
