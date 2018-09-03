#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
int mn[maxn<<2];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        mn[rt]=l==1?0:-1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

void update(int l,int r,int rt,int p,int x)
{
    if(l==r)
    {
        mn[rt]=x;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(l,mid,rt<<1,p,x);
    else update(mid+1,r,rt<<1|1,p,x);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

int query(int l,int r,int rt,int x)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(mn[rt<<1]<x) return query(l,mid,rt<<1,x);
    return query(mid+1,r,rt<<1|1,x);
}

int main()
{
    int n,c;
    scanf("%d",&n);
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c);
        int ans=query(1,n,1,i-c);
        printf("%d",ans);
        if(i!=n) printf(" ");
        update(1,n,1,ans,i);
    }
    return 0;
}
