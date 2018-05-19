#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define inf -1000000000000000000
using namespace std;

int main()
{
    long long m,n,a[55],b[55],c[55],i,j,t,mx;
    scanf("%lld%lld",&m,&n);
    for(i=0; i<m; i++)
        scanf("%lld",&a[i]);
    for(i=0; i<n; i++)
        scanf("%lld",&b[i]);

    for(i=0;i<m;i++)
    {
        mx=inf;
        for(j=0;j<n;j++)
        {
            mx=max(mx,a[i]*b[j]);

        }
        c[i]=mx;

    }
    sort(c,c+m);



        printf("%lld\n",c[m-2]);
        return 0;
    }
