#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll mod;


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

ll Pow(ll a,ll n,ll r)
{
    ll ans=1,base=a;
    for(;n;n>>=1)
    {
        if(n&1) ans=ans*base%r;
        base=base*base%r;
    }
    return ans;
}

int main()
{
    ll p,q,e,l,c,d,x,y,r;
    while(scanf("%lld%lld%lld%lld",&p,&q,&e,&l)!=EOF)
    {
        mod=(p-1)*(q-1);
        r=p*q;
        d=inverse(e,mod);
        while(l--)
        {
            scanf("%d",&c);
            printf("%c",Pow(c,d,r));
        }
        printf("\n");
    }
    return 0;
}
