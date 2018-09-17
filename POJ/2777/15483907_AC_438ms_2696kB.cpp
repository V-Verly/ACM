#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int tree[maxn<<2],lazy[maxn<<2];

void up(int rt)
{
    tree[rt]=tree[rt<<1]|tree[rt<<1|1];
}

void down(int rt)
{
    if(!lazy[rt]) return;
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    tree[rt<<1]=tree[rt<<1|1]=lazy[rt];
    lazy[rt]=0;
}

void build(int l,int r,int rt)
{
    tree[rt]=lazy[rt]=0;
    if(l==r)
    {
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    up(rt);
}

void update(int l,int r,int rt,int p,int x,int y)
{
    if(x>r||y<l) return;
    if(x<=l&&r<=y)
    {
        tree[rt]=lazy[rt]=1<<(p-1);
        return;
    }
    down(rt);
    int mid=(l+r)>>1;
    update(l,mid,rt*2,p,x,y);
    update(mid+1,r,rt*2+1,p,x,y);
    up(rt);
}

int query(int l,int r,int rt,int x,int y)
{
    if(x>r||y<l) return 0;
    if(x<=l&&r<=y)
        return tree[rt];
    down(rt);
    int mid=(l+r)>>1;
    return query(l,mid,rt*2,x,y)|query(mid+1,r,rt*2+1,x,y);
}

int solve(int x)
{
    int ans=0;
    while(x)
    {
        if(x&1) ans++;
        x>>=1;
    }
    return ans;
}

int main()
{
    int n,t,m,a,b,c;
    char op[5];
    while(scanf("%d%d%d",&n,&t,&m)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%s",op);
            if(op[0]=='C')
            {
                scanf("%d%d%d",&a,&b,&c);
                if(a>b) swap(a,b);
                update(1,n,1,c,a,b);
            }
            else
            {
                scanf("%d%d",&a,&b);
                if(a>b) swap(a,b);
                printf("%d\n",solve(query(1,n,1,a,b)));
            }
        }
    }
    return 0;
}
