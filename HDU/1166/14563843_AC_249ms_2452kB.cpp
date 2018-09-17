#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define Lson l,mid,rt*2
#define Rson mid+1,r,rt*2+1
using namespace std;

const int maxn=5e4+10;
int a[maxn],tree[4*maxn];

void pushup(int rt)
{
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void update(int l,int r,int rt,int p,int x)
{
    if(l==r)
    {
        tree[rt]+=x;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(Lson,p,x);
    if(p>mid) update(Rson,p,x);
    pushup(rt);
}

int query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return tree[rt];
    int mid=(l+r)>>1,ans=0;
    if(x<=mid) ans+=query(Lson,x,y);
    if(y>mid) ans+=query(Rson,x,y);
    return ans;
}

int main()
{
    int t,n,x,y;
    char op[10];
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n,1);
        printf("Case %d:\n",k);
        while(scanf("%s",op)!=EOF&&op[0]!='E')
        {
            scanf("%d%d",&x,&y);
            if(op[0]=='Q')
                printf("%d\n",query(1,n,1,x,y));
            else if(op[0]=='A')
                update(1,n,1,x,y);
            else
                update(1,n,1,x,-y);
        }
    }
    return 0;
}
