#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    scanf("%lld",&n);
    n++;
    if(n==1) printf("0\n");
    else if(n%2==0)
    {
        printf("%lld\n",n/2);
    }
    else
        printf("%lld\n",n);
    return 0;
}
