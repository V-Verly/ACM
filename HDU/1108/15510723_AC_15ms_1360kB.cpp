#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",a/__gcd(a,b)*b);
    }
    return 0;
}
