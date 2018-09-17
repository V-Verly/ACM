#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e5+10;
int lsum[maxn],rsum[maxn],msum[maxn];
int lazy[maxn];

void up(int l,int r,int rt)
{
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    int mid=(l+r)>>1;
    if(lsum[rt]==mid-l+1) lsum[rt]+=lsum[rt<<1|1];
    if(rsum[rt]==r-mid) rsum[rt]+=rsum[rt<<1];
    msum[rt]=max(lsum[rt<<1|1]+rsum[rt<<1],max(msum[rt<<1],msum[rt<<1|1]));
}

void down(int l,int r,int rt)
{
    if(lazy[rt]==-1) return;
    int mid=(l+r)>>1;
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lsum[rt<<1]=rsum[rt<<1]=msum[rt<<1]=lazy[rt]?0:mid-l+1;
    lsum[rt<<1|1]=rsum[rt<<1|1]=msum[rt<<1|1]=lazy[rt]?0:r-mid;
    lazy[rt]=-1;
}

void build(int l,int r,int rt)
{
    lsum[rt]=rsum[rt]=msum[rt]=r-l+1;
    lazy[rt]=-1;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void update(int l,int r,int rt,int x,int y,int op)
{
    if(x<=l&&r<=y)
    {
        lsum[rt]=rsum[rt]=msum[rt]=op?0:r-l+1;
        lazy[rt]=op;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt*2,x,y,op);
    if(y>mid) update(mid+1,r,rt*2+1,x,y,op);
    up(l,r,rt);
}

int query(int l,int r,int rt,int x)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    down(l,r,rt);
    if(msum[rt<<1]>=x) return query(l,mid,rt*2,x);
    if(rsum[rt<<1]+lsum[rt<<1|1]>=x) return mid-rsum[rt<<1]+1;
    return query(mid+1,r,rt*2+1,x);
}

int main()
{
    int m,n,op,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&x);
                if(msum[1]<x) printf("0\n");
                else
                {
                    int q=query(1,n,1,x);
                    printf("%d\n",q);
                    update(1,n,1,q,q+x-1,1);
                }
            }
            else
            {
                scanf("%d%d",&x,&y);
                update(1,n,1,x,x+y-1,0);
            }
        }
    }
}
