#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

int a[maxn],c[maxn],x[maxn],y[maxn];

inline int lowbit(int x) {return x&(-x); }

int sum(int x)
{
    int ret=0;
    while(x>0) {ret+=c[x]; x-=lowbit(x); }
    return ret;
}

void add(int x,int d)
{
    while(x<=100000) {c[x]+=d;x+=lowbit(x); }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(c,0,sizeof c);
        for(int i=0;i<n;i++)
        {
            x[i]=sum(a[i]);
            add(a[i],1);
        }
        memset(c,0,sizeof c);
        for(int i=n-1;i>=0;i--)
        {
            y[i]=sum(a[i]);
            add(a[i],1);
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans+=x[i]*(n-i-y[i]-1)+(i-x[i])*y[i];
        printf("%lld\n",ans);

    }
    return 0;
}
