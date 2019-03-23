#include <bits/stdc++.h>

using namespace std;

const int maxn=2e5+10;

int n,a[maxn],mod;
int tree[maxn<<2];

void pushup(int i) {tree[i]=max(tree[i<<1],tree[i<<1|1]); }

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}

void update(int l,int r,int rt,int x,int val)
{
    if(l==r)
    {
        tree[rt]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt<<1,x,val);
    else update(mid+1,r,rt<<1|1,x,val);
    pushup(rt);
}

int query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y) return tree[rt];
    int mx=0,mid=(l+r)>>1;
    if(x<=mid) mx=max(mx,query(l,mid,rt<<1,x,y));
    if(y>mid) mx=max(mx,query(mid+1,r,rt<<1|1,x,y));
    return mx;
}

int main()
{
    scanf("%d%d",&n,&mod);
    char op[5];
    int lq=0,cnt=1,x;
    build(1,n,1);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",op,&x);
        if(op[0]=='A') update(1,n,1,cnt++,(lq+x)%mod);
        else
        {
            lq=query(1,n,1,cnt-x,cnt);
            printf("%d\n",lq);
        }
    }
    return 0;
}
