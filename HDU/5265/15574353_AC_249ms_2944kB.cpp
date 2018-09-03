#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;
ll a[maxn];

bool cmp(const ll &a,const ll &b)
{
    return a>b;
}

int main()
{
    int n;
    ll p;
    while(scanf("%d%lld",&n,&p)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]%=p;
        }
        sort(a,a+n,cmp);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int pos=lower_bound(a,a+n,p-a[i]-1,greater<int>())-a;
            if(pos==i) pos++;
            if(pos!=n) ans=max(ans,(a[i]+a[pos])%p);
            pos=lower_bound(a,a+n,2*p-a[i]-1,greater<int>())-a;
            if(pos==i) pos++;
            if(pos!=n) ans=max(ans,(a[i]+a[pos])%p);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
