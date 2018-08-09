#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long quickpower(long long a,long long n)
{
    long long ans=1,base=a;
    while(n)
    {
        if(n&1) ans=ans*base%10;
        base=base*base%10;
        n>>=1;
    }
    return ans;
}

int main()
{
    long long a,b,s;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",quickpower(a,b)%10);
    }
    return 0;
}
