#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;

ll fastpower(int a,ll n)
{
    ll ans=1,base=a;
    while(n)
    {
        if(n&1) ans=(ans*base)%mod;
        base=(base*base)%mod;
        n>>=1;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    if(!n) return 0*printf("1\n");
    ll ans=fastpower(2,n-1)*(fastpower(2,n)+1)%mod;
    cout<<ans<<endl;
    return 0;
}
