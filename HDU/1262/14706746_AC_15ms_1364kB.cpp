#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        for(int i=m/2;i>=2;i--)
        {
            if(isprime(i)&&isprime(m-i))
            {
                printf("%d %d\n",i,m-i);
                break;
            }
        }
    }
    return 0;
}
