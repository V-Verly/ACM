#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        printf("Case %d: ",_);
        scanf("%lld",&n);
        double tmp=n;
        ll ans=(ll)sqrt(tmp)+(ll)sqrt(tmp/2);
        printf("%lld\n",n-ans);
    }
    return 0;
}
