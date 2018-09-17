#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod=9973;

void extgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b){ d=a; x=1; y=0;}
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }
}

ll inverse(ll a,ll n)
{
    ll d,x,y;
    extgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

int main()
{
    int t;
    ll n,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&b);
        ll inv=inverse(b,mod);
        printf("%lld\n",n*inv%mod);
    }
    return 0;
}
