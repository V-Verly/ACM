#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[10005];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[n/2]);
    }
    return 0;
}
