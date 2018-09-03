#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5e4+10;
int a[maxn],tree[4*maxn];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void update(int l,int r,int rt,int x,int y,int v)
{
    if(x<=l&&r<=y)
    {
        tree[rt]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt*2,x,y,v);
    if(y>mid) update(mid+1,r,rt*2+1,x,y,v);
}

void query(int l,int r,int rt,int x,int ans)
{
    if(l==r&&x==l)
    {
        printf("%d\n",tree[rt]+ans);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) query(l,mid,rt*2,x,tree[rt]+ans);
    if(x>mid) query(mid+1,r,rt*2+1,x,tree[rt]+ans);
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
            update(1,n,1,l,r,c);
        else
            query(1,n,1,r,0);
    }
    return 0;
}
