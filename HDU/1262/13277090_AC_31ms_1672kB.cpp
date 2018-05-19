#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime(int x)
{
    if(x==2) return true;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        t=n/2;
        while(t>=2)
        {
            if(prime(t)&&prime(n-t)) break;
            t--;
        }
        printf("%d %d\n",t,n-t);
    }
    return 0;
}
