#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    while((a>=2*b||b>=2*a)&&a&&b)
    {
        a%=2*b;
        if(a) b%=2*a;
    }
    printf("%lld %lld\n",a,b);
    return 0;
}
