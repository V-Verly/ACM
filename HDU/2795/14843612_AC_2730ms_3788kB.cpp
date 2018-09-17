#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
int h,w;
int tree[4*maxn];

void build(int l,int r,int rt)
{
    if(l==r) {tree[rt]=w;return; }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    tree[rt]=max(tree[rt*2],tree[rt*2+1]);
}

int query(int l,int r,int rt,int x)
{
    if(l==r) {tree[rt]-=x;return l; }
    int mid=(l+r)/2;
    int ans=(tree[rt*2]>=x)?query(l,mid,rt*2,x):query(mid+1,r,rt*2+1,x);
    tree[rt]=max(tree[rt*2],tree[rt*2+1]);
    return ans;
}

int main()
{
    int n,x;
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        h=min(h,n);
        build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(tree[1]<x) printf("-1\n");
            else printf("%d\n",query(1,h,1,x));
        }
    }
    return 0;
}
