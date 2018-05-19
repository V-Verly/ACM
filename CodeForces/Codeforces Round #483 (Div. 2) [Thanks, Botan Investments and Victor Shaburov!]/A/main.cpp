#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[1005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(n%2)
    {
        printf("%d\n",a[n/2]);
    }
    else
    {
        printf("%d\n",a[n/2-1]);
    }
    return 0;
}
