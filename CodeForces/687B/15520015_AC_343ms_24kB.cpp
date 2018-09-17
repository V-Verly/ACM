#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll lcm(ll x,ll y) {return x/__gcd(x,y)*y; }

int main()
{
    ll n,k,cur=1;
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++)
    {
        ll x;
        scanf("%lld",&x);
        cur=__gcd(k,lcm(cur,x));
    }
    printf("%s\n",cur==k?"Yes":"No");
    return 0;
}
