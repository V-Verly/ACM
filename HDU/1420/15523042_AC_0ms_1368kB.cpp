#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Pow(ll a,ll n,ll mod)
{
    ll ans=1,base=a;
    for(;n;n>>=1)
    {
        if(n&1) ans=ans*base%mod;
        base=base*base%mod;
    }
    return ans;
}

int main()
{
    int t;
    ll a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%d\n",Pow(a,b,c));
    }
    return 0;
}
