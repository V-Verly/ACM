#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long a[35],b[35],x,y;
    a[0]=1,b[0]=0;
    for(int i=1;i<34;i++)
    {
        a[i]=3*a[i-1]+2*b[i-1];
        b[i]=a[i-1]+b[i-1];
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%lld, %lld\n",a[n],b[n]);
    }
    return 0;
}
