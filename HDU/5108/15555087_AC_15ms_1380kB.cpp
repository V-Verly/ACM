#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e6+10;

bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int solve(int n)
{
    int ans=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(isprime(i)) ans=i;
            if(isprime(n/i)) ans=n/i;
        }
    }
    if(isprime(n)) ans=n;
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1) {printf("0\n");continue; }
        printf("%d\n",n/solve(n));
    }
    return 0;
}
