#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int tree[4*maxn],a[maxn];

void build(int l,int r,int rt)
{
    tree[rt]=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void update(int l,int r,int rt,int x)
{
    if(l==r)
    {
        tree[rt]++;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt*2,x);
    if(x>mid) update(mid+1,r,rt*2+1,x);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}

int query(int l,int r,int rt,int x,int y)
{
    if(x<=l&&r<=y)  return tree[rt];
    int mid=(l+r)>>1,ans=0;
    if(x<=mid) ans+=query(l,mid,rt*2,x,y);
    if(y>mid) ans+=query(mid+1,r,rt*2+1,x,y);
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(0,n-1,1);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=query(0,n-1,1,a[i],n);
            update(0,n-1,1,a[i]);
        }
        int ans=sum;
        for(int i=0;i<n;i++)
        {
            sum+=n-2*a[i]-1;
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
