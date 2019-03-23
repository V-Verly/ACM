#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
const int maxn=1e6+10;

typedef long long ll;

ll pow(ll a,ll b=mod-2)
{
    ll ans=1,base=a;
    while(b)
    {
        if(b&1) (ans*=base)%=mod;
        (base*=base)%=mod;
        b>>=1;
    }
    return ans;
}

int ans[maxn];

int main()
{
    int t,n;

    ll a=1,b=1,c=1,x;
    for(int i=1;i<=1000000;i++)
    {
        a=a*(2*i-1)%mod*(2*i)%mod;
        b=b*i%mod;
        c=c*(i+1)%mod;
        x=pow(b*c%mod);
        ans[i]=a*x%mod;
    }
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        printf("Case #%d:\n%lld\n",_,ans[n]);
    }
    return 0;
}
