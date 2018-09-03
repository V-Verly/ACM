#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=4e6+10,inf=0x3f3f3f3f;
long long sum[maxn];
int mx[maxn],mn[maxn];

void update(int l,int r,int rt,int p,int x)
{
    if(l==r)
    {
        sum[rt]=mx[rt]=mn[rt]=x;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)
        update(l,mid,rt*2,p,x);
    else
        update(mid+1,r,rt*2+1,p,x);
    sum[rt]=sum[rt*2]+sum[rt*2+1];
    mx[rt]=max(mx[rt*2],mx[rt*2+1]);
    mn[rt]=min(mn[rt*2],mn[rt*2+1]);
}

void query(int l,int r,int rt,int ll,int rr,long long  &a,int &b,int &c)
{
    if(ll<=l&&r<=rr)
    {
        a+=sum[rt];
        b=max(b,mx[rt]);
        c=min(c,mn[rt]);
        return;
    }
    int mid=(l+r)/2;
    if(ll<=mid) query(l,mid,rt*2,ll,rr,a,b,c);
    if(rr>mid) query(mid+1,r,rt*2+1,ll,rr,a,b,c);
}

int main()
{
    int m,n,op,x,y;
    scanf("%d%d",&n,&m);
    memset(sum,0,sizeof(sum));
    memset(mx,0,sizeof(mx));
    memset(mn,0,sizeof(mn));
    while(m--)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(!op) update(1,n,1,x,y);
        else
        {
            long long sum=0;
            int maxv=-inf,minv=inf;
            query(1,n,1,x,y,sum,maxv,minv);
            printf("%lld\n",sum-maxv-minv);
        }
    }
}
