#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=2e4+10;

int main()
{
    int n,m,a[maxn],b[maxn];
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n+m;i++)
            scanf("%d",&a[i]);
        sort(a,a+n+m);
        int s=0;
        printf("%d",a[0]);
        for(int i=1;i<m+n;i++)
        {
            if(a[i]!=a[i-1])
                printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
