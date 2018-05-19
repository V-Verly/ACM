#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}



int main()
{
    int t;
    long long p,q,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&p,&q,&b);
        long long m=gcd(p,q);
        p/=m;
        q/=m;

    }
    return 0;
}
