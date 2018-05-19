#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,s,t;
    scanf("%d",&t);
    while(t--)
    {
        s=3;
        scanf("%d",&n);
        while(n--)
            s=s*2-2;
        printf("%d\n",s);
    }
    return 0;
}
