#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        int t=__gcd(m,n);
        printf("%s\n",t!=1?"YES":"NO");
    }
    return 0;
}
