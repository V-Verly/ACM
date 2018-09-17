#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    long long fib[55];
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<50;i++)
        fib[i]=fib[i-1]+fib[i-2];
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%lld\n",fib[b-a]);
    }
    return 0;
}
